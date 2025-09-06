/*
Pointers - key code & terms
- pointer 
    - A variable that stores the memory address of another variable
- address operator (&)
    - returns the memory address of a variable
- dereference operator (*)
    - returns the value stored at the address pointer to by a pointer
- void pointer
    - Used to hold a pointer of any data type but cannot be dereferenced itself
*/

#include <stdio.h>

void incrementInt(int* integer);
void main2();

int main() {

    main2();
    return 0;

    int age = 25;
    printf("%p\n", &age); // %p is the format specifier for pointer addresses  

    // create a pointer 
    int *pAge = &age;
    // increment age by passing it's reference to a function 
    incrementInt(pAge);
    printf("%d\n", age);

    // Void pointers provided a way to return a general address, disregarding the 
    // type of data being stored at that address.
    void * alloc();
    int *vals = (int *) alloc(42);

}

// functions in C are passed by value
void incrementInt(int* integer) {
    // we must include brackets around the dereference operator 
    // because the increment operator takes precedence over the * operator
    // the * operator will return the value stored at the memeory address
    // then the increment operator will increase it's value by 1
    (*integer)++;
}

void main2() {

    // Pointer arithmetic 
    char ca[10], *cp;
    int ia[10], *ip;

    cp = ca + 1;
    ip = ia + 1;

    printf("ca %p cp %p\n", ca, cp);
    printf("ia %p ip %p\n", ia, ip);

    /* When incrementing and decrementing pointers 
    the address increases by the size of it's type 
    for example if an integer pointer had the address 
    0004 incrementing by one would increse the address by 4 bytes
    0008
    */


}