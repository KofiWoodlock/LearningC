/*
Key code and terms 
- array
    - Contiguous block of memory used to store data of the same type (homogenous)
    with a fixed size
*/

#include <stdio.h>

int main() {

    int percentages[] = {71 , 63, 52, 40, 25, 10};
    char grades[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // display percentage matching to the grade
    for (int i = 0; i < 6; i++) {
        printf("%d %c for an %c\n", percentages[i], 37, grades[i]);
    }

    return 0;
}