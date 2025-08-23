/*
Memory management - key terms & code
- Heap
    - A region of memory used for dyanmic allocation
- Stack
    - A regions of memory used for storing local variables, function parameters
    and return addresses; automatically managed when functions are called & 
    return
- Malloc
    - A function used to allocate a specified number of bytes of memory onto the 
    heap
- Calloc
    -
- Realloc
    -
- Free
    - A function used to free memory allocated on the heap
- Dangling pointer
    - A pointer that references memory that has been freed and can result in 
    undefined behaviour
*/

#include <stdio.h>

int main() {

    /* In the case where the size of a structure such as an array is not known
    before compilation we must dynamically allocate memory
    */

    // Grade array example
    // Allow user to enter n amount of grades into an array
    
    int num_of_grades = 0;  // The user can decide how many grades they want to enter
    printf("Enter the number of grades you want to enter: ");
    scanf("%d", &num_of_grades);

    /* If one char grade uses 1 byte then we need n bytes to store n grades*/
    char *grades = malloc(sizeof(char)*num_of_grades);

    free(grades); // WE MUST RETURN MEMORY WE USED BY USING free() TO AVOID LEAKS
    grades = NULL; // WE MUST ALSO SET OUR POINTER TO NULL TO AVOID DANGALING POINTERS

    return 0;
}