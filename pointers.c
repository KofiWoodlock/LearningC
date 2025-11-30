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
#include <ctype.h>

#define SIZE 4
#define BUFSIZE 100

void incrementInt(int* integer);
void pntrs();
void swap(int *px, int *py);
int getint(int *pn);
int getch(void);
void ungetch(int c);
int strlen(char *s);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int main() {

    pntrs();

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

    printf("---- getint ----\n");
    int n, nums[SIZE];
    for (n = 0; n < SIZE && getint(&nums[n]) != EOF; n++)
        ;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
        printf("nums[%d]: %d\n", i, nums[i]);

    /* POINTER ARITHMETIC */
    printf("---- Pointer arithmetic ----\n");
    /* Any operations that can be performed by array subscripting can be 
        achieved by using pointers
    */
    int intArr[10]; // declares an integer array of size 10
    int *pa; // declares an integer pointer 
    pa = &intArr[0]; // Sets pa to point to the 0th element in the integer array
    int x = *pa; // Sets x to be the VALUE of pa that is the value of intArr[0] 
    pa + 1; // Increments pa to be the next address in the array namely intArr[1]
    /* pa + i; will point pa i elements after pa and likewise with pa - i in the other
    direction 
    *(pa+i);  returns the Value of the contents of intArr[i]
    In c the name of an array is an alias for the adrress of the first element
    so as shorthand we can write 
        */
    pa = intArr;
    int i = 1;
    // The statements are the same
    intArr[i] == *(intArr + i);
    &intArr[i] == intArr+i;
    pa[i] == *(pa+i);
}

// functions in C are passed by value
void incrementInt(int* integer) {
    // we must include brackets around the dereference operator 
    // because the increment operator takes precedence over the * operator
    // the * operator will return the value stored at the memeory address
    // then the increment operator will increase it's value by 1
    (*integer)++;
}

void pntrs() {

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

void swap(int *px, int *py) {
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}

/* returns the next integer from input stream into *pn */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* Not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn +  (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/* get a possibly pushed back character */
int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back onto input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* Returns the length of a string */
int strlen(char *s) {
    int len;
    
    for (len = 0; *s != '/0'; s++)
        len++;
    return len;
}