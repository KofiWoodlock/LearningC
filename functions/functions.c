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
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

bool adultCheck(int age) {
    if (age >= 18) {
        return true;
    }
    return false;
}

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

    bool res = ageCheck(21);
    printf("%s", res ? "true" : "false");

    return 0;
}