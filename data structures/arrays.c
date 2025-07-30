/*
Key code and terms 
- array
    - Contiguous block of memory used to store data of the same type (homogenous)
    with a fixed size
*/

#include <stdio.h>

int main() {

    int percentages[] = {71 , 63, 52, 40, 25, 10, 5};
    int len_percentages = sizeof(percentages) / sizeof(percentages[0]);
    char grades[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char *names[7];
    names[0] = "Name1";
    names[1] = "Name2";
    names[2] = "Name3";
    names[3] = "Name4";
    names[4] = "Name5";
    names[5] = "Name6";
    names[6] = "Name7";

    // display percentage matching to the grade
    for (int i = 0; i < len_percentages; i++) {
        printf("%s scored %d %c for an %c\n",names[i], percentages[i], 37, grades[i]);
    }


    return 0;
}