#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //prompt user for a string
    string s = GetString();
    int i = 0;
    
    //select first letter per word and print it capitalised
    if (s != NULL)
    {
        if (islower(s[i]) || isupper(s[i]))
        {
            printf("%c", toupper(s[0]));
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if (s[i] == ' ')
                {
                    printf("%c", toupper(s[i+1]));
                }
            }
                printf("\n");
        }
    }
}
