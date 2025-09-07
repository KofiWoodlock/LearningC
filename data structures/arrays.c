/*
Key code and terms 
- array
    - Contiguous block of memory used to store data of the same type (homogenous)
    with a fixed size
- 2d array
    - An array comprised of other arrays
*/

#include <stdio.h>

void get_scores();
void buffer_overflow();

int main() {

    buffer_overflow();
    return 0;

    // Create and initialise single dimensional array
    // general code to initialise an array: type array_name[] = {x, y, z};
    int percentages[] = {71 , 63, 52, 40, 25, 10, 5};
    int len_percentages = sizeof(percentages) / sizeof(percentages[0]);
    char grades[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char *names[7];
    names[0] = "Name1";
    names[1] = "Name2";
    names[2] = "Name3";
    names[3] = "Name4";
    names[4] = "Name5";
    names[5] = "Name6";
    names[6] = "Name7";
    // get_scores();

    // Declare and initialise two dimensional array
    // general code to initialise a 2d array: type array_name[][n] = {{a, b, c}, {e,f, g}, {x, y, z}};
    // n is the number of columns / elements within each subarray 

    int nums[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    // we can calculate the number of elements within a subarray using the following formula:
    // number of bytes used to store array / number of bytes of 1 element within the array.
    // in C code it looks like this:
    int len_nums = sizeof(nums) / sizeof(nums[0]);

    // general code to print elemnts from a 2d array is as follows:
    // printf("format specifier", array_name[n][m]);
    // where n is the index of the subarray and m is the index of the value within that subarray

    printf("%d\n", nums[0][0]);

    // if we wanted to print every element from the any n subarray we could use a loop:

    // int subarray_index = 2; // index of sub_array 
    
    // printf("[");
    // for (int i = 0; i < 3; i++) {
    //     printf("%d ", nums[subarray_index][i]);
    // }
    // printf("]");

    // we can use nested loops to display the entire contents of our 2d array (matrix)

    printf("\n");

    for (int row = 0; row < len_nums; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", nums[row][col]);
        }
        printf("\n");
    }

    // // display percentage matching to the grade
    // for (int i = 0; i < len_percentages; i++) {
    //     printf("%s scored %d %c for an %c\n",names[i], percentages[i], 37, grades[i]);
    // }

}

void get_scores() {

    // set size of uninitialised array
    int scores[5] = {0};
    int len_scores = sizeof(scores) / sizeof(scores[0]);

    for (int i = 0; i < len_scores; i++) {
        printf("Please enter a score: ");
        scanf("%d", &scores[i]);
    }
    printf("Scores: ");
    for (int i = 0; i < len_scores; i++) {
        printf("%d, ", scores[i]);
    }
}

/* Testing out a buffer overflow */
void buffer_overflow() {
    // A buffer overflow occurs when we try to insert more memory into a space 
    // than we have allocated 

    char unsafe_string[15];
    gets(unsafe_string);
    printf("%s\n", unsafe_string);
}