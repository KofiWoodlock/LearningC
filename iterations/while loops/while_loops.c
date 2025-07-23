/*
While loops - key code & terms 
- while loop
    - A type of indefinite iteration that continues whilst some condition is true 
- do while loop
    -  Executes a block of code once and then checks whether some condition is true
*/

#include <stdio.h>

int main() {

    // Regular while loop
    // int num = 0;

    // while (num <= 0) {
    //     printf("Enter a number!\n");
    //     scanf("%d", &num);
    // }

    int num = 0;

    // Do while loop
    do {
        printf("Please enter a number greater than 0: ");
        scanf("%d", &num);
    } while (num <= 0);

    return 0;
}