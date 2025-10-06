/* Key terms & code
    - Extern
        - a keyword used to define an external variable or function defined
        within another source file
*/

#include <stdio.h>

extern int speed;
extern int durability;
extern char name[];

int main() {
    printf("Name: %s\n", name); 
    printf("Speed: %d\n", speed); 
    printf("Durability: %d\n", durability); 
    return 0;
}