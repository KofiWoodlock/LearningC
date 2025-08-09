/*
Enums - key code & terms
- enumeration 
    - A user-defined data-type that contains a set of named integer constants 
- set
    - A mutable unordered collection of values homogenous in type
*/

#include <stdio.h>

typedef enum {
    MONDAY = 1,
    TUEESDAY = 2, 
    WEDNESDAY = 3, 
    THURSDAY = 4, 
    FRIDAY = 5, 
    SATURDAY = 6, 
    SUNDAY = 7
}Day;

typedef enum{
    SUCCESS,
    FAILED,
    PENDING
}Status;

void connect(Status status);

int main() {

    Day today = MONDAY;

    Status status = PENDING;
    connect(status);

    return 0;
}

void connect(Status status) {
    switch (status) {
        case SUCCESS:
            printf("Great success!\n");
            break;
        case FAILED:
            printf("Oh no fail!\n");
            break;
        case PENDING:
            printf("50/50");
            break;
    }
}