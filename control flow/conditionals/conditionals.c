/*
Key code and terms 
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

void ageCheck();
void studentCheck();
void nameCheck();
int binarySearch(int arr[], int len, int x);

int main() {

    int NUMS[] = {1,2,3,4,5,6,7,8,9};
    int nums_length = sizeof(NUMS) / sizeof(int);
    int res;

    nameCheck();
    res = binarySearch(NUMS, nums_length, 1);
    printf("%d", res);
    return 0;
}

void ageCheck() {
    int age = 0;

    printf("Please enter your age: ");
    scanf("%d", &age);

    /* Else if statement chains are evaluated in order sequentially.
    Each expression is tested until one returns a truthy value then the
    associated statement or block of statements are executed */
    if (age >= 18 && age < 65) {
        printf("You are an adult");
    } else if (age >= 65) {
        printf("You are an elderly person");
    } else if (age < 0) {
        printf("You have not been born yet");
    } else {
    // Else if chains can be terminated with an else statement 
    // That handles the 'None of the above case'
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

/* Determines whether x occurs in the sorted array*/
int binarySearch(int arr[], int len, int x) {

    int l = 0;
    int r = len - 1;
    int m;
    while (l <= r) {
        m = (l+r) / 2;
        if (arr[m] == x)
            return m;
        else if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    } 
    return -1;
}