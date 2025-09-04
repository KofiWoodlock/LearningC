/*
While loops - key code & terms 
- while loop
    - A type of indefinite iteration that continues whilst some condition is true 
- do while loop
    -  Executes a block of code once and then checks whether some condition is true
*/

#include <stdio.h>
#include <stdlib.h>

void guessTheNum();

int main() {

    // Regular while loop
    // int num = 0;

    // while (num <= 0) {
    //     printf("Enter a number!\n");
    //     scanf("%d", &num);
    // }

    int num = 0;

    // Do while loop
    // do {
    //     printf("Please enter a number greater than 0: ");
    //     scanf("%d", &num);
    // } while (num <= 0);

    guessTheNum();

    return 0;
}

/* Small game where user has to guess the number i am thinking of */
void guessTheNum() {
    int num, guess;

    num = 60;
    printf("Try to guess the number i am thinking of between 1-100!\n");

    while (scanf("%d", &guess) != EOF) {
        if (guess == num) {
            printf("Correct!\n");
            break;
        } else if (guess < num)
            printf("Go higher!\n");
        else
            printf("Go lower!\n");
    }
}