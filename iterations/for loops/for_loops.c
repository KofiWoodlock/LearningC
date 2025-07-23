/*
For loops - key code & terms 
- for loop
    - A type of definite iteration that allows code to be repeated a set number
    of times 
- increment operator (++)
    - Increases the value of a variable by one 
- decrement operator (--)
    - Decreases the valeu of a varaible by one
*/

#include <stdio.h>
#include <windows.h>

int main() {

    // // Count up to 10

    // for (int i = 0; i < 10; i++) {
    //     printf("%d\n", i);
    // }
    
    // Count down from 10

    for (int j = 10; j > 0; j--) {
        Sleep(1000);
        printf("%d\n", j);
    }

    return 0;
}