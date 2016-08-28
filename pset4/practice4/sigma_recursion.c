/**
* implementing a recursion function
* 
*/

#include <stdio.h>
#include <cs50.h>

int sigma(int m);

int main(void)
{
    int n;
    
    do
    {
        printf("Give me a positive int: \n");
        
        n = GetInt();
    }
    while (n < 0);
    
    int r = sigma(n);
    
    printf("%d \n", r);
}

int sigma(int m)
{
    // base case
    if (m < 1)
    {
        return 0;
    }
    
    // recursion
    else 
    {
        return m + sigma(m - 1);
    }
}