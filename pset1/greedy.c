#include <cs50.h>
#include <stdio.h>
#include <math.h>

float getPositiveFloat(void);

int main (void)
{
    float f = getPositiveFloat();
    int n = roundf(f * 100.0f);
    //printf("%d\n", n);
    int c;
    int r;
    while (n > 0)
    {
        if (n >= 25)
        {
            c = n / 25;
            r = c;
            n = n % 25;
        } 
        if (n >= 10)
        {
            c = n / 10;
            r = r + c;
            n = n % 10;
        } 
        if (n >= 5)
        {
            c = n / 5;
            r = r + c;
            n = n % 5;
        } 
        if (n >= 1)
        {
            c = n / 1;
            r = r + c;
            n = n % 1;
        } 
        else {}
    }
        printf("%d\n", r);
}

float getPositiveFloat(void)
{
    float f;
    do
    {
        printf("Please give me a positive float: ");
        f = GetFloat();
    } 
    while (f <= 0.0);
    return f;
}
