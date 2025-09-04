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
- windows.h
    - Windows specific header file containing functions in the Windows API
- ctype.h
    - Header file that declares set of functions to classify & transform chars 
*/

#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

int sqr(int x);
int strToInt(char s[]);
void reverseStr(char s[]);
void expand(char s1[], char s2[]);
static int same_class(int a, int b);

int main() {

    char output[1024] = {0};

    expand("a-z0-9", output);
    printf("Output: %s", output);
    return 0;

    char name[] = "Jeff";
    printf("Name: %s\n", name);
    reverseStr(name);
    printf("Reversed name: %s\n", name);
    return 0;

    char num[] = "-210";
    printf("%s\n", num);
    int res; 
    res = strToInt(num);
    printf("%d", res);

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

/* Returns the square of integer x */
int sqr(int x) {
    return x * x;
}

/* Converts string s to an integer keeping it's sign */
int strToInt(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ; // Skip whitespace
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++; // Skip sign
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* Reverses string s in place */
void reverseStr(char s[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
        temp = s[i];
        s[i]= s[j];
        s[j] = temp;
    }
}

static int same_class(int a, int b) {
    return isdigit(a) && isdigit(b) ||
           islower(a) && islower(b) ||
           isupper(a) && isupper(b);
}

/* Takes shorthand notation in s1 and converts it to a full list in s2*/
void expand(char s1[], char s2[]) {
    int i, j = 0;
    
    for (i = 0; i < s1[i] != '\0'; i++) {
        if (s1[i] == '-' &&
            i > 0 && s1[i] != '\0' && // cases of leading or trailing -
            same_class(s1[i-1], s1[i+1]) && // check range is valid i.e a-z not a-9
            s1[i-1] < s1[i+1]) { // check range is ascending only i.e not z-a

            int start = s1[i-1]; // starting character of range
            int end = s1[i+1]; // ending character of range

            for (int c = start+1; c < end; c++) {
            // copies range into s2
            s2[j++] = c;
           }
        } else 
            s2[j++] = s1[i];
    }
    s2[j] = '\0'; // add null terminator to allow printing via %s
}