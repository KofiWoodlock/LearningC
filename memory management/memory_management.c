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
    - (Contiguous allocation) a function to allocate memory dynamically and set all bytes to 0
- Realloc
    - A function used to resize previously allocated memory
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

void printCharArr(char *arr, int len);
void printIntArr(int *arr, int len);
void useCalloc();
void useRealloc();

int main() {

    useRealloc();
    return 0;

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

    printCharArr(grades, num_of_grades);

    free(grades); // WE MUST RETURN MEMORY WE USED BY USING free() TO AVOID LEAKS
    grades = NULL; // WE MUST ALSO SET OUR POINTER TO NULL TO AVOID DANGALING POINTERS

    return 0;
}

void printCharArr(char *arr, int len) {
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

void printIntArr(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i == len-1) {
            printf("%d", arr[i]);
            continue;
        } else
            printf("%d,", arr[i]);
    }
    printf("]");
}


void useCalloc() {
    
    int num_of_players = 0;
    printf("Enter the number of players: ");
    scanf("%d", &num_of_players);

    int *scores = calloc(num_of_players, sizeof(int));
    if (scores == NULL) {
        printf("Error allocating memory");
    }

    for (int i = 0; i < num_of_players; i++) {
        printf("Enter player %d's score: ", i+1);
        scanf(" %d", &scores[i]);
    }

    printIntArr(scores, num_of_players);

    // Returning the apartment & key
    free(scores); // ALWAUS FREE MEMROY 
    scores = NULL; // ALWAYS SET POINTER TO NULL

}

void useRealloc() {

    int num_of_prices = 0;
    printf("Enter the number of prices to set: ");
    scanf("%d", &num_of_prices);
    float *prices = malloc(sizeof(float)*num_of_prices);
    if (prices == NULL) {
        printf("Error allocating memory");
    }

    for (int i = 0; i < num_of_prices; i++) {
        printf("Enter price No.%d: ", i+1);
        scanf("%f", &prices[i]);
    }

    int new_prices = 0;
    // realloc() allows us to dynamically increase or decrease the size of our memory
    printf("How many prices would you like to add? ");
    scanf("%d", &new_prices);

    float *tmp = realloc(prices, new_prices*sizeof(float));
    if (tmp == NULL) {
        printf("Error reallocating memory\n");
    } else {
        prices = tmp;
        tmp = NULL;

        for (int i = num_of_prices; i < num_of_prices+new_prices; i++) {
            printf("Enter price No.%d: ", i+1);
            scanf("%f", &prices[i]);
        }
    }

    for (int i = 0; i < num_of_prices+new_prices; i++) {
        printf("Price No.%d: %.2f\n", i+1, prices[i]);
    }

    // Returning the apartment & key
    free(prices); // ALWAUS FREE MEMROY 
    prices = NULL; // ALWAYS SET POINTER TO NULL
    
}
