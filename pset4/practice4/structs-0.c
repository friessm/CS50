#include <stdio.h>
#include <cs50.h>
#include <string.h>

#include "structs.h"

// hash-define constant variable
#define STUDENTS 3

int main(void)
{
    // declare an array called students and specify its size with 3
    student students[STUDENTS];
    
    // iterate over the array and prompt the user for the name and houses of the students
    for (int i = 0; i < STUDENTS; i++)
    {
        // prompt for name and store it in the i-th position of the array
        printf("Name: ");
        students[i].name = GetString();
        
        // prompt for house and store it in the i-th position of the array
        printf("House: ");
        students[i].house = GetString();
    }
    
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("%s lives in house %s \n", students[i].name, students[i].house);
    }
    
    // free memory which was allocated by GetString(), which calls malloc in order to allocate memory for the strings the user types
    for (int i = 0; i < STUDENTS; i++)
    {
        free(students[i].name);
        free(students[i].house);
    }
}