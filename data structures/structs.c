/*
Structs - key code & terms
- structure 
    - A custom container that holds multiple realted variables of different types
    (heterogenous)
*/

#include <stdio.h>
#include <stdbool.h>

// define a structure
typedef struct {
    char name[50]; // each variable is a member of the strucrture 
    int age;
    float gpa;
    bool isFullTime;
}Student;


int main() {
    
    Student student1 = {"Joe", 14, 3.4, true};
    Student student2 = {"Bob", 16, 3.0, false};
    // to declare a struct but not assign any members we must clear out the memory
    // to clear any garbage values that persisted from other programs
    Student student3 = {0}; // this sets all the members to 0

    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.1f\n", student1.gpa);
    printf("Full time: %s\n", (student1.isFullTime) ? "true" : "false");

    printf("Name: %s\n", student2.name);
    printf("Age: %d\n", student2.age);
    printf("GPA: %.1f\n", student2.gpa);
    printf("Full time: %s\n", (student2.isFullTime) ? "true" : "false");

    return 0;
}