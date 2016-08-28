#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //if the user puts in the correct command line argument 'return 0' if not 'return 1'
    if (argc == 2)
    {
        //convert command line input to int
        int k = atoi(argv[1]);
        
        //prompt for plaintext and store in variable s
        string s = GetString();
    
        //encypher the plaintext stored in variable s with variable k
        if (s != NULL)
        {
            //executing caesar's cypher with for loop and if conditions inside the for loop 
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if (isblank(s[i]) || isdigit(s[i]) || ispunct(s[i]))
                {
                    printf("%c", s[i]);
                } 
                if (isupper(s[i]))
                {
                    s[i] = (s[i] - 65 + k) % 26;
                    s[i] = s[i] + 65;
                    printf("%c", s[i]);
                }
                if (islower(s[i]))
                {
                    s[i] = (s[i] - 97 + k) % 26;
                    s[i] = s[i] + 97;
                    printf("%c", s[i]);
                }
            }
            printf("\n");
        }
        return 0;
    }
    else 
    {
        printf("Yell\n");
        return 1;
    }
}
