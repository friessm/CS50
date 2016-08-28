#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //convert command line input to int
    int k = atoi(argv[1]);
    
    if (k > 0)
    {
        printf("\n%d\n", k);

        //prompt for plaintext and store in variable s
        printf("Plaintext: ");
        string s = GetString();
    
        //encypher the plaintext stored in variable s with variable k
        if (s != NULL)
        {
            //int i = 0;
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                printf("%c", s[i] + k);
            }
            printf("\n\n");
        }
        return 0;
    }
    else 
    {
        return 1;
    }
}
