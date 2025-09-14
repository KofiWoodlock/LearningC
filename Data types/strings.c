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

void printlongest();
int getline(char s[], int lim);
int getlinev2(char s[], int lim);
void copy(char s[], char t[]);
void rmblanks(char in[], char out[]);
void reversestr(char *s);
int any(char s1[], char s2[]);

int main() {

    char m[] = "Hello World";
    char n[] = " ";
    int res = any(m, n);
    printf("Res: %d", res);
    return 0;

    // Strings in C are represented by arrays of chars
    // char string[] = "Hello";
    // printf("%s\n", string);

    char message[] = "Tom Twinkleberry";
    printf("Original: %s\n", message);
    reversestr(message);
    printf("Reversed: %s\n", message);

    /* We must always terminate a char array (string) with a null terminator '\0',
    to indicate the end of the string, 
    Additionally, because strings are really char arrays whenever we want to,
    concatenate data to the end of a string we need to ensure there is enough, 
    space within the underlying character array. */
}

/* Reads lines of text and prints the longest line */
void printlongest() {

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
    for (i = 0; i < lim-1 && (c = getchar() != EOF) && c != '\n'; ++i) 
        s[i] = c; // copy current line into the string (char array)
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Reads a line into s and returns it's length */
int getlinev2(char s[], int lim) {

    // Alternative getline function without using && or ||

    int c, i;

    // Loop until we see a newline character, get to end of file or reach max line length
    for (i = 0; i < lim-1; ++i) {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        s[i] = c; // copy current line into the string (char array)
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    printf("Line: %s", s);
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
void reversestr(char *s) {
    // // Intuitive solution is to copy input backwards into new data structure
    // // then overwrite original string with reversed copy

    // int i;
    // int j = 0;

    // char tmp[1024]; // temp string to hold reversed values

    // for (int i = strlen(s); i > 0; --i) {
    //     s[i] = tmp[j];
    //     j++;
    // }
    // for (int i = 0; i < strlen(tmp); ++i) {
    //     printf("%c", tmp[i])s 
    // }

    // Two pointer solution 
    int l = 0;
    int r = strlen(s) - 1;
    char tmp;

    while (l < r) {
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

/* Returns the first occurence of any character from s2 in s1 */
int any(char s1[], char s2[]) {
    
    int i, j;

    // loop through s1
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[0])
            return i;
        else
            for (j = 1; s2[j] != '\0'; j++) {
                if (s1[i] == s2[j])
                    return i;
            }
    }
    return -1; // No s2 chars found 
}