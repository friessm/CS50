#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Say something: ");
    char* s = GetString();
    if (s == NULL)
    {
        return 1;
    }
    
    // malloc == memory allocation: returns the address of a chunk of memory of a certain size of bytes
    // stlen(s) + 1: we want as many bytes as 's' already occupies PLUS the null-terminator \0
    char* t = malloc((strlen(s) + 1) * sizeof(char));
    
    // check if malloc fails to return the memory we need
    if (t == NULL)
    {
        free(s);
        return 1;
    }
    
    // copying the string s to string t
    // i <= n: so that i iterate up to and including the null-terminator '\0' of s
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        *(t + i) = *(s + i);
    }
    
    printf("Capitalysing copy ... \n");
    
    // sanity testing
    if (strlen(s) > 0)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            *(t + i) = toupper(*(t + i));
        }
    }
    
    printf("Original: %c \n", *s);
    printf("Copy:     %c \n", *t);
    
    free(s);
    free(t);
}