/*
Ternary operator - key code & terms
- Ternary operator ?
    - Shorthand syntax for if-else statements
*/

#include <stdio.h>

int max(int x, int y) {
    // Takes two integers and returns larger one
    return (x > y) ? x : y;
}

int main() {

    // Military clock 
    int mins = 3;
    int hours = 15;
    char *meridium = (hours < 12) ? "AM" : "PM";

    printf("%02d:%02d %s", hours, mins, meridium);

    return 0;
}
