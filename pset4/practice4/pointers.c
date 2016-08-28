#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // a string is a pointer, hence char*
    char* s = GetString();
    
    // error checking
    if (s == NULL)
    {
        // return immediately, so we don't accidently de-reference that NULL-pointer
        return 1;
    }
    
    for (int i = 0, n = strlen(s); i < n; i ++)
    {
        // go to the address that equals the sum of s + i
        // the address of the first character of the sring is stored in 's'
        printf("%c \n", *(s + i));
    }
}