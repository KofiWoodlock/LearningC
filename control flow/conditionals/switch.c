/*
Key code and terms 
- Switch 
    - Keyword used to test some expression and matches one of a number of cases
*/ 


#include <stdio.h>
#include <string.h>

void countNumsSpacesOthers();
void escape(char s[], char t[]);

int main() {

    /* General structure of a switch statemnt:
    switch (expression) {
        case const-expr: statement
        case const-expr: statement
        default: statement
    }
    */

    char in[] = "Hi My name is JeFF";
    char out[1024] = {0};

    escape(in, out);

    printf("%s", in);
    printf("\n");
    printf("%s", out);

    return 0;
}

/* Counts the number of digits, white spaces and other characters in an input*/
void countNumsSpacesOthers() {

    int c, i, ndigit[10];
    int nwhite = 0;
    int nother = 0;

    // Initialize digits array 
    for (i =0; i < 10; i++) {
        ndigit[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4': 
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
            case ' ': 
            case '\t': 
            case '\n':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    printf("Number of digits:\n");
    for (i = 0; i < 10; i++)
        printf("No.%d: %d\n", i, ndigit[i]);
    printf("Num of white spaces: %d\n", nwhite);
    printf("Num of other chars: %d\n", nother);
}

/* Copies string s into t converting escape sequences to printable chars */
void escape(char s[], char t[]) {

    int i, j;

    j = 0;
    for (i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '\n':
                t[j] = '\\';
                j ++;
                t[j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                j ++;
                t[j] = 't';
                break;
            default:
                t[j] = s[i];
                j++;
        }
    }
}