/**
 * save students to disk in a csv file with file I/O
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"

#define STUDENTS 3

int main(void)
{
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
    
    // write students' information in a csc file
    // create a file and open it with 'fopen'; w is short for 'write'
    FILE* file = fopen("students.csv", "w");
    // error checking
    if (file != NULL)
    {
        for (int i = 0; i < STUDENTS; i++)
        {
            // print to a file with 'fprintf'
            fprintf(file, "%s,%s \n", students[i].name, students[i].house);
        }
        // close the file
        fclose(file);
    }
    
    // free memory that was allocated by GetString(), which calls malloc in order to allocate memory for the strings the user types
    for (int i = 0; i < STUDENTS; i++)
    {
        free(students[i].name);
        free(students[i].house);
    }
}