/* File copying program */

#include <stdio.h>

void printEOF();
void character_counting();

/* copy input to output */
int main() {
    character_counting();
    return 0;
}

/* Prints the value of EOF */
void printEOF() {
    int c;
    while ((c = getchar()) != EOF) {
        printf("Signal EOF!!\n");
    }
    printf("%d\n", c);
}

/* Count the number of characters in an input stream */
void character_counting() {

    long numChars = 0;
    while (getchar() != EOF) {
        numChars++;
    }
    printf("Input was %ld characters long\n", numChars); 
}