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
- call by value 
    - Proccess of passing an argument to a function in which a copy is made that
    can be modified at the local scope, leaving the original variable unaltered 
- call by reference
    - 
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
int strindex(char s[], char t[]);
int strindexr(char s[], char t[]);
void callByValue(int arg);
void zap(char s[]);

int main() {

    /*
    int age = 0;
    char name[50] = "";

    printf("\nEnter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';
    printf("Enter your age: ");
    scanf("%d", &age); 
    happyBirthday(age, name);

    double res = square(2.5);
    printf("%.2lf", res);

    bool res = adultCheck(21);
    printf("%s\n", res ? "true" : "false");

    double output = square(2);
    printf("%2.lf\n", output);

    printf("%d\n", strindex("hello world", "o"));
    

    int var = 5; // main function variable 
    printf("var (main scope) before : %d\n", var);
    callByValue(var); // pass a copy of var
    printf("var (main scope) after: %d\n", var);


    char message[] = "Hello Aliens";
    printf("String (main scope): %s\n", message);
    zap(message); // when passing an array we actually pass a pointer to the array 
    printf("String (main scope): %s\n", message); // the main scope string is modified by zap
    */

    int index;
    char txt[] = "acbcdc";
    printf("Leftmost index: %d\n", strindex(txt, "c"));
    printf("Rightmost index: %d\n", strindexr(txt, "c"));

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

/* Returns the first index of t in s*/
int strindex(char s[], char t[]) {
    int i, j ,k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++);

        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/*
len_s = 5
len_t = 1 

s = "abcdc"
t = "c"
*/

/* Returns the rightmost index of t in s*/
int strindexr(char s[], char t[]) {
    // Compute lengths of strings initially 
    int i, j, k, len_s, len_t;
    
    for (len_s = 0; s[len_s] != '\0'; len_s++);
    for (len_t = 0; t[len_t] != '\0'; len_t++);

    for (i = len_s - len_t; len_s > 0; i--) {
        for (j = i, k = 0; k < len_t && s[j] == t[k]; j++, k++);
        if (k == len_t)
            return i;
    }
    return -1;
}

void callByValue(int arg) {
    printf("arg (local scope) before: %d\n", arg);
    arg = arg + 10;
    printf("arg (local scope) after: %d\n", arg);
}

/* Modifies the passed string to say ZAPPED! */
void zap(char s[]) {
    printf("String before zap: %s\n", s);
    strcpy(s, "ZAPPED!");
    printf("String after zap: %s\n", s);
}