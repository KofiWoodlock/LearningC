/*
Pointers - key code & terms
- pointer 
    - A variable that stores the memory address of another variable
- address operator (&)
    - returns the memory address of a variable
- dereference operator (*)
    - returns the value stored at the address pointer to by a pointer
- void pointer
    - Used to hold any type of pointer but cannot be dereferenced itself
*/

#include <stdio.h>

void incrementInt(int* integer);

int main() {

    int age = 25;
    printf("%p\n", &age); // %p is the format specifier for pointer addresses  

    // create a pointer 
    int *pAge = &age;
    // increment age by passing it's reference to a function 
    incrementInt(pAge);
    printf("%d\n", age);

    return 0;
}

// functions in C are passed by value
void incrementInt(int* integer) {
    // we must include brackets around the dereference operator 
    // because the increment operator takes precedence over the * operator
    // the * operator will return the value stored at the memeory address
    // then the increment operator will increase it's value by 1
    (*integer)++;
}