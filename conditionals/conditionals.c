// Key code and terms 
/*
- conditional 
    - A control flow statement that allows a program to execute different
    blocks of code depending on wether certain conditions are ture of false
*/

#include <stdio.h>

int main() {

    int age = 12;

    if (age >= 18) {
        printf("You are an adult");
    } else {
        printf("You are not an adult");
    }

    return 0;
}