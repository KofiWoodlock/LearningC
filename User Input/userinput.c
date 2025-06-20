#include <stdio.h>
#include <string.h>

int main() {
    // create int and char variables
    char full_name[30]; 
    int age;

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
    printf("Enter your full name\n");
    fgets(full_name, 30, stdin);    
    // fgets comes with a preset \n 
    // if we want to remove that we need to edit the last index of our char array and set it to \0
    //full_name[strlen(full_name)-1] = '\0';

    printf("Hello %s", full_name);
    

    return 0;
}