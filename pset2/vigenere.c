#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

    /*     calculate the i-th char of keyword to the i-th char of the plaintext
    apply modulo operator to the keyword to wrap around it until the end of the plaintext */

int main(int argc, string argv[])
{
    // store keyword in 's'
    string s = argv[1];
    
    // test of modulo operator
    // int y = 2 % 2;
    // printf("%d\n", y);
       
    // prompt for plaintext and store it in 'p'
    string p = GetString();
    
    if (s != NULL)
    {
        for (int i = 0, n = strlen(p), x = strlen(s); i < n; i++)
            {
                if (isdigit(p[i]) || isspace(p[i]) || ispunct(p[i]))
                {
                    printf("%c", p[i]);
                }
                if (isalpha(p[i]) && isupper(p[i]))
                {
                    p[i] = p[i] - 65;
                    s[i] = s[i] - 65;
                    p[i] = (p[i] + s[i]) % 26;
                    p[i] = p[i] + 65;
                    printf("%c", p[i]);
                    // s % strln(s) or x
                }
                if (isalpha(p[i]) && islower(p[i]))
                {
                    p[i] = p[i] - 97;
                    s[i] = s[i] - 97;
                    p[i] = (p[i] + s[i]) % 26;
                    p[i] = p[i] + 97;
                    printf("%c", p[i]);
                }
            }  
        
    }
    printf("\n");
}

