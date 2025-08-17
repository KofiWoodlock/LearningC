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

typedef struct{
    char brand[25];
    char model[50];
    int topSpeed;
    float price;
}Car;

void printStudentInfo(Student student);
void printCarInfo(Car car);

int main() {
    
    Student student1 = {"Joe", 14, 3.4, true};
    Student student2 = {"Bob", 16, 3.0, false};
    // to declare a struct but not assign any members we must clear out the memory
    // to clear any garbage values that persisted from other programs
    Student student3 = {0}; // this sets all the members to 0

    // We can also create arrays of structs 

    Car cars[] = {{"Audi", "RS3", 155, 70000.00},
                  {"Corvette", "C7 ZR1", 190, 95000.00},
                  {"Porsche", "911 Carrera 4S", 191, 130000.00}};
    int cars_length = sizeof(cars) / sizeof(cars[0]);

    // we can use a for loop to print out the members of each struct 
    for (int i = 0; i < cars_length; i++) {
        printf("Make: %s, Model: %s, Top Speed: %d, Price: %c%.2f\n", cars[i].brand, cars[i].model, cars[i].topSpeed, 156, cars[i].price);
    }

    return 0;
}

void printStudentInfo(Student student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.1f\n", student.gpa);
    printf("Full time: %s\n", (student.isFullTime) ? "true" : "false");
    printf("\n");
}
