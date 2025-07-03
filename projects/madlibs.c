// Madlibs game 
// Features: 
// - User can enter a noun
// - User can enter an adjective 
// - User can enter a verb
// - User can enter an adverb 
// - A sentance is output composed from the entered words 

/* 
Key code 
- Char array
    - A data type that is used to store a collection of characters or strings
- strlen
    - Returns the length of a string (number of characters up until the first null terminating character)
- string.h
    - Header file in C standard lib for string handling  
*/

#include <stdio.h>
#include <string.h>

int main() {

    // Main body
    char noun[50] = "";
    char verb[50] = "";
    char adjective[50] = "";
    char adjective1[50] = "";
    char adjective2[50] = "";

    printf("Enter an adjective: ");
    fgets(adjective, sizeof(adjective), stdin);
    adjective[strlen(adjective) - 1] = '\0';
    printf("Enter a noun: ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';
    printf("Enter an adjective: ");
    fgets(adjective1, sizeof(adjective1), stdin);
    adjective1[strlen(adjective1) - 1] = '\0';
    printf("Enter a verb ending in (ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) - 1] = '\0';
    printf("Enter an adjective: ");
    fgets(adjective2, sizeof(adjective2), stdin);
    adjective2[strlen(adjective2) - 1] = '\0';

    printf("Today i went to a %s city\n", adjective);
    printf("In the city i saw a %s\n", noun);
    printf("%s was %s and %s!\n", noun, adjective1, verb);
    printf("I was %s\n", adjective2);

    return 0;
}