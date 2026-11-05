#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*
Key terms and symbols:
- Address Operator (&)
    - returns the address of a variable
- null terminator ('\0')
    - a character with an internal value of 0 to denote the end of a string
- stream
    - a seqeunce of data that is read one byte at a time
- printf
    - function used to print formatted data to the stdout
- scanf
    - function used to read formatted data from stdin
- fgets (FileGetString)
    - function used to get a string from a steam
- sizeof
    - returns the size in bytes of the specified operand
- getchar
    - Takes a single input character from stdio, only can take a single input stream
- variable length arguments
    - In c a function can take any number of arguments denoted by ... at the end of 
    an argument list e.g. function(arg1, arg2, ...); 
- va_list
    - data type to declare a variable that referes to each argument of a variable
    argument list
- va_start
    - macro that initialises a varg pointer to the first unnamed argument
- va_arg
    - macro that returns an argument and steps to the next argument in the varg list
- va_end
    - macro to cleanup
*/

void minprintf(char *fmt, ...);

int main() {
    // create int and char variables
    // best practice to assign default values to initialised variables 
    // to prevent undefined behaviour if the variable is used before it 
    // is assigned a value
    char name[30] = ""; 
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0'; // null terminator 

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
    // printf("Enter your full name\n");
    // fgets(name, 30, stdin);    
    // fgets comes with a preset \n 
    // if we want to remove that we need to edit the last index of our char array and set it to \0
    //full_name[strlen(full_name)-1] = '\0';

    // printf("Hello %s", name);

    minprintf("Integer: %d double: %f string: %s", 10, 12.376, "Hello Boy!"); 
    return 0;
}

/* Minial printf function to demnstrate variable length arguments in C */
void minprintf(char *fmt, ...) 
{
    va_list vargp; /* varaible argument list pointer */
    char *p, *strval;
    int ival;
    double dval;

    va_start(vargp, fmt); /* Set pointer to point at first variable argument */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(vargp, int);
                printf("%d", ival);
                break;  
            case 'f':
                dval = va_arg(vargp, double);
                printf("%f", dval);
                break;
            case 's':
                for (strval = va_arg(vargp, char *); *strval; strval++)
                    putchar(*strval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(vargp);
}