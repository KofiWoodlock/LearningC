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
- Segmentation fault
    - An error that occurs when a program attempts to access a memory address 
    that it is not allowed access to
*/

#include <stdio.h>
#include <stdlib.h>

void printarr(char *arr, int len);

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

    // If an error occurs in the malloc function NULL is returned
    // We must check for this as derefencing a NULL pointer can lead to a
    // segmentation fault
    if (grades == NULL) {
        printf("Error allocating memory!");
        return 1;
    }

    // Assign some grades 
    for (int i = 0; i < num_of_grades; i++) {
        printf("Enter grade No.%d ", i+1);
        scanf(" %c", &grades[i]);
    }

    printarr(grades, num_of_grades);

    free(grades); // WE MUST RETURN MEMORY WE USED BY USING free() TO AVOID LEAKS
    grades = NULL; // WE MUST ALSO SET OUR POINTER TO NULL TO AVOID DANGALING POINTERS

    return 0;
}

void printarr(char *arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i == len-1) {
            printf("%c", arr[i]);
            continue;
        } else
            printf("%c,", arr[i]);
    }
    printf("]");
}