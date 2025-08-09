/*
Typedef - key code & terms
- typedef 
    - keyword used to give names to existing datatypes
*/

#include <stdio.h>

typedef int num;
typedef char* string;

int main() {

    num x = 3;
    num y = 4;
    num z = x + y;

    printf("%d\n", z);

    string message = "Hello World";
    printf("%s\n", message);

    return 0;
}