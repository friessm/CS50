/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    // count jpgs
    int counter_jpg = 0;

    // buffer to store resulting string and null terminator from sprintf
    char img_test[8];
    
    // initialise buffer
    uint8_t* buffer = malloc(512);
    
    FILE* img = NULL;

    // open CompactFlash disc
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        fclose(card);
        perror("Could not open file");
        return 1;
    }

    while(fread(buffer, 512, 1, card) == 1)
    {
        // check first four bytes of the block for a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // first jpg is found
            if (img != NULL)
            {
                fclose(img);
            }

            // generate new jpg and open it
            sprintf(img_test, "%03d.jpg", counter_jpg);
            img = fopen(img_test, "w");
            if (img == NULL)
            {
                fclose(img);
                perror("Could not open file");
                return 2;
            }   
            
            // write to img
            fwrite(buffer, 512, 1, img);
            
            // increment file counter
            counter_jpg++;
        }
        
        // if file is open write to it
        else if (img != NULL)
        {
            // write to img
            fwrite(buffer, 512, 1, img);
        }
    }

    // close CompactFlash disc
    fclose(card);
    
    // free memory allocated by malloc
    free(buffer);
    
        
    // the End
    return 0;
}
