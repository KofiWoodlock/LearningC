/* 
Key code & terms

- function 
    - A reusable block of code that can be invoked by calling the function with
    it's required arguments if necessary  
- main
    - The starting function of every C program
- return type
    - The data type of the value that is returned after the execution of a
    function
- void 
    - This indicates a function does not return a value 
- pointer
    - Variable that stores the memory address of another variable and it's value
- dereference operator (*)
    - Used to get the value stored at a memory address pointed to by a pointer
- return
    - Keyword used to return a value from a function 
- ternary conditional operator (x? y:z)
    - if x condition if true then return y if not return z 
- variable scope
    - Where a variable is recognisable and accessible
- function prototype
    - Provides compiler with information about a functions return type, name
    & parameters before the function is defined  
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// If we want to organise our code and put the functions below the main function
// we need to specify function prototypes so we don't get a function declaration
// error 

void happyBirthday(int age, char name[]); // function prototype 
double square(double num);
double cube(double num);
double add(double x, double y);
double subtract(double x, double y);
bool adultCheck(int age);


int main() {

    // int age = 0;
    // char name[50] = "";

    // printf("\nEnter your name: ");
    // fgets(name, sizeof(name), stdin);
    // name[strlen(name)-1] = '\0';
    // printf("Enter your age: ");
    // scanf("%d", &age); 
    // happyBirthday(age, name);

    // double res = square(2.5);
    // printf("%.2lf", res);

    bool res = adultCheck(21);
    printf("%s", res ? "true" : "false");

    double output = square(2);
    printf("%2.lf", output);

    return 0;
}

void happyBirthday(int age, char name[]) {
    printf("\nHappy birthday to you");
    printf("\nHappy birthday to you");
    printf("\nHappy birthday dear %s!", name);
    printf("\nHappy birthday to you");
    printf("\nYou are %d years old!", age);
}

double square(double num) {
    return num * num;
}

double cube(double num) {
    return num * num * num;
}

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

bool adultCheck(int age) {
    if (age >= 18) {
        return true;
    }
    return false;
}