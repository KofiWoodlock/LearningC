/*
Strings - Key terms & code
- String
    - An array of characters 
- getchar()
    - Reads a single character from the stdin strean
- EOF
    - "End OF File" a constant defined in stdlib used to denote end of a file
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

void getlongest();
int getline(char s[], int lim);
void copy(char s[], char t[]);
void rmblanks(char in[], char out[]);
char *reversestr(char s[]);

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
    /* We can make small tweaks to this conditional check to modify
    the purpose of the program */
        // if (len > 80)
        //     printf("%s", line); This prints all lines greater than 80 characters
        if (len > max) {
            copy(line, longest);
        }
    if (max > 0) // Check if there were any lines 
        printf("Longest line: %s\n", longest);

}

/* Reads a line into s and returns it's length */
int getline(char s[], int lim) {

    int c, i;

    // Loop until we see a newline character, get to end of file or reach max line length
    for (i = 0; i < lim && (c = getchar() != EOF) && c != '\n'; ++i) 
        s[i] = c; // copy current line into the string (char array)
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Copies string s into string t */
void copy(char s[], char t[]) {

    int i = 0;
    while (t[i] = s[i] != '\0')
        ++i;
}

/* Removes all trailing whitespace, tabs and blank lines from input */
/* Assumes only trailing whitespace, assumes no whitespace in input */
void rmblanks(char in[], char out[]) {

    int i = 0;
    // Loop until we get to end of the line
    while (in[i] != '\0') {
        if (in[i] != ' ' && in[i] != '\t') {
            out[i] = in[i];
            i++;
        }
        else
        // If we see a whitespace or tab ignore it and do not copy it
            i++; 
    }     
}

/* Reverses input string s */
char *reversestr(char s[]) {
    // Intuitive solution is to copy input backwards into new data structure
    // then overwrite original string with reversed copy

    int i;
    int j = 0;

    char tmp[] = {0}; // temp string to hold reversed values

    for (int i = strlen(s); i > 0; --i) {
        s[i] = tmp[j];
        j++;
    } 

    return tmp;
}