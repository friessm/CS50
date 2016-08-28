/**
 * compare two strings: a pointer exercise
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // char* is the address of the first character of a sequence of characters
    printf("Say something: ");
    char* s = GetString();
    
    printf("Say something: ");
    char* n = GetString();
    
    // error checking; make sure nothing bad happened, for example we ran out of memory or the user somehow did not cooperate
    // otherwise a segmentation fault can happen
    if (s != NULL && n != NULL)
    {
        // use function strcmp "string compare" to compare the two arrays of chars
        if (strcmp(s, n) == 0)
        {
            printf("You typed the same thing! \n");
        }
        else
        {
            printf("You typed different things! \n");
        }
    }
}