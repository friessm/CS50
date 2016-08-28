/**
 * swapping two original values with pointers
 */

#include <stdio.h>

void swap(int* a, int* b);

int main(void)
{
  // declaring two integer values
  int x = 1;
  int y = 2;

  printf("x is %d \n", x);
  printf("y is %d \n", y);
  printf("\nSwapping ... \n");

  // swap function
  // & means that we are passing in the addresses of x and y into the function and by that we are swapping x and y
  swap(&x, &y);

  printf("\nSwapped \n\n");
  printf("x is %d \n", x);
  printf("y is %d \n", y);
}

void swap(int* a, int* b)
{
  // we don't change the value of a, instead we change the value AT a, since a is an address; same goes for b
  int temp = *a;
  *a = *b;
  *b = temp;
}
