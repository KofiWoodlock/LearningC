#include <stdio.h>
#include <string.h>

/*
Key terms and symbols:
- Address Operator (&)
    - returns the address of a variable
- null terminator ('\0')
    - a character with an internal value of 0 to denote the end of a string
- stream
    - a seqeunce of data that is read one byte at a time
- printf
    - function used to print formatted data to the stdout
- scanf
    - function used to read formatted data from stdin
- fgets
    - function used to get a string from a steam
*/

int main() {
    // create int and char variables
    // best practice to assign default values to initialised variables 
    // to prevent undefined behaviour if the variable is used before it 
    // is assigned a value
    char name[30] = ""; 
    int age = 0;
    float gpa = 0.0f;
    char grade = "\0"; // null terminator 

    /*
    // Ask user to enter first name and age
    printf("Enter your first name and your age: \n");
    // Get and save the first name and age user types
    scanf("%s %d", first_name, &age);
    // Print their name
    printf("Welcome, %s \n", first_name);
    // Print their age
    printf("Your age is: %d \n", age);
    */

    // if a user input contains whitespace we need to use fgets function
    // printf("Enter your full name\n");
    // fgets(name, 30, stdin);    
    // fgets comes with a preset \n 
    // if we want to remove that we need to edit the last index of our char array and set it to \0
    //full_name[strlen(full_name)-1] = '\0';

    // printf("Hello %s", name);

    printf("Enter your name:\n");
    fgets("%s", 30, &name);
    printf("Enter your age:\n");
    scanf("%d", &age);
    printf("Enter your gpa:\n");
    scanf("%f", &gpa);
    printf("Enter your grade:\n");
    scanf(" %c", &grade);

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%f\n", gpa);
    printf("%c\n", grade);
    

    return 0;
}