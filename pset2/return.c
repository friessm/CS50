#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    if (argc == 2)
    {
        printf("Good\n");
        return 0;
    }
    if (argc != 2)
    {
        printf("Bad\n");
        return 1;
    }
}
