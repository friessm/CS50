/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember factor
    int n = atoi(argv[1]);
    
    // check if n is positive and less than or equal to 100
    if (n < 1 && n >= 100)
    {
        return 5;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf; // bf is 54 bytes big --- bf is sizeof(BITMAPFILEHEADER) bytes big
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // add new variable instead of bf and bi which are for the infile
    BITMAPFILEHEADER bf_out;
    BITMAPINFOHEADER bi_out;

    // copy BITMAPFILEHEADER and BITMAPINFOHEADER into outfile's header variables
    memcpy(&bf_out, &bf, sizeof(BITMAPFILEHEADER));
    memcpy(&bi_out, &bi, sizeof(BITMAPINFOHEADER));
    
    // change member's value
    bi_out.biWidth = bi.biWidth * n; 
    bi_out.biHeight = bi.biHeight * n;
    
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_out = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // change member's value which are dependent on size of padding
    bi_out.biSizeImage = (bi_out.biWidth * 3 + padding_out) * abs(bi_out.biHeight);
    bf_out.bfSize = bi_out.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr); 

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr); 

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // vertical: adding new pixels / bytes
        for (int v = 0; v < n; v++)
        {
            // ensure to not use fseek while scanning the first line for the first time
            if (v != 0)
            {
                // reposition stream position indicator to the beginning of the scanline
                fseek(inptr, - (abs(bi.biWidth) * sizeof(RGBTRIPLE) + padding), SEEK_CUR);
            }
            
            // iterate over pixels in scanline 
            for (int j = 0; j < bi.biWidth; j++) 
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // horizontal: adding new pixels / bytes
                for (int h = 0; h < n; h++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr); 
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
    
            // then add it back (to demonstrate how)
            for (int k = 0; k < padding_out; k++)
            {
                fputc(0x00, outptr); 
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
