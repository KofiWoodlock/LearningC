/*
For loops - key code & terms 
- for loop
    - A type of definite iteration that allows code to be repeated a set number
    of times 
- increment operator (++)
    - Increases the value of a variable by one 
- decrement operator (--)
    - Decreases the valeu of a varaible by one
- break
    - A keyword used to exit an iteration
- continue
    - A keyword used to skip to the next pass within an iteration
- nested loop
    - A loop that is within another loop
*/

#include <stdio.h>
#include <windows.h>

int sqr(int x) {
    return x * x;
}

int main() {

    // Count up to 10

    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    // Count down from 10

    for (int j = 10; j > 0; j--) {
        Sleep(1000);
        printf("%d\n", j);
    }

    for (int i = 0; i < 101; i++) {
        if (i % 2 != 0) {
            continue;
        }
        Sleep(1000);
        printf("%d\n", i);
    }

    // nested loops
    for (int i = 1; i < 11; i++) {
        printf("i: %d\n", i);
        for (int j = 1; j < 11; j ++) {
            printf("j: %d\n", sqr(j));
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            printf("j: %d\n", j);
        }
        printf("\n");
    }

    // MULTIPLICATION TABLE 
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j ++) {
            printf("%d ", j*i);
        }
        printf("\n");
    }

    // FUNNY DRAWING 
    char symbol = '\0';
    printf("Enter a character: ");
    scanf(" %c", &symbol);

    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            if (i < 2 && j == 4) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
            if ((i > 1 && i < 5) && (j == 3 || j == 4)) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        } 
        printf("\n");
    }

    return 0;
}