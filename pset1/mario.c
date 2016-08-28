#include <cs50.h>
#include <stdio.h>

unsigned int GetPositiveInt(void);

int main(void)
{
    unsigned int n = GetPositiveInt();
    char h = '#';
    for (unsigned int i = 1; i <= n; i++)
    {
        printf("%*c", n - i + 1, h);
        for (unsigned int j = 1; j <= i; j++)
        {
            printf("%c", h);
        } 
        printf("\n");
    }
}

unsigned int GetPositiveInt(void)
{
    int n;
    do
    {
        printf("Height: ");
        n = GetInt();
    }
    while (n < 0 || n > 23);
    return (unsigned int)(n);
}




