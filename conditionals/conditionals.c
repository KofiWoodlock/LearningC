// Key code and terms 
/*
- conditional 
    - A control flow statement that allows a program to execute different
    blocks of code depending on wether certain conditions are ture of false
- equality operator (==)
    - Returns true if both operands have the same value
- inequality operator (!=)
    - Returns true if both operands do not have the same value
- AND operator (&&)
    - Returns true if both operands are true otherwise returns false
- OR operator (||)
    - Returns true if either operand is true otherwise returns false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ageCheck() {
    int age = 0;

    printf("Please enter your age: ");
    scanf("%d", &age);

    if (age >= 18 && age < 65) {
        printf("You are an adult");
    } else if (age >= 65) {
        printf("You are an elderly person");
    } else if (age < 0) {
        printf("You have not been born yet");
    } else {
        printf("You are not an adult");
    }
    printf("\n");
}

void studentCheck() {
    bool isStudent = false;

    if (isStudent) {
        printf("You are a student");
    } else {
        printf("You are not a student");
    }
    printf("\n");
}

void nameCheck() {
    char name[50] = "";

    printf("Plese enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    if (strlen(name) == 0) {
        printf("You did not enter your name!");
    } else {
        printf("%s", name);
    }
}

int main() {

    nameCheck();
    return 0;
}