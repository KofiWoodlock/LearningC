/*
Strings - Key terms & code
- String
    - An array of characters 
- getchar()
    - Reads a single character from the stdin strean
- EOF
    - "End OF File"
*/

#include <stdio.h>

#define MAXLINE 1024

void getlongest();
int getline(char s[], int lim);
void copy(char s[], char t[]);

int main() {
    // Strings in C are represented by arrays of chars 
    char string[] = "Hello";
    printf("%s", string);

    return 0;
}

/* Reads lines of text and prints the longest line */
void printLongest() {

    int len; // Keeps track of each line's length
    int max; // Longest line length
    char line[MAXLINE]; // Stores currernt line
    char longest[MAXLINE]; // Stores longest line

    while (len = getline(line, MAXLINE) > 0)
        if (len > max) {
            copy(line, longest);
        }
    if (max > 0) // Check if there were any lines 
        printf("Longest line: %s\n", longest);

}

/* Reads a line and returns the string and it's length */
int getline(char s[], int lim) {

    int c, i;

    // Loop until we see a newline character, get to end of file or reach max line length
    for (i = 0; i < lim && (c = getchar() != EOF) && c != '\n'; ++i) { 

    }

    return 0;
}

/* Copies string s into string t */
void copy(char s[], char t[]) {}
