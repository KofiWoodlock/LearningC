#include <stdio.h>
#include <ctype.h>
#include <string.h>

void strtolower(void);
void strtoupper(void);

int main(int argc, char const *argv[])
{
    if (strcmp("lower", argv[1]) == 0) {
        strtolower();
    } else if (strcmp("upper", argv[1]) == 0) {
        strtoupper();
    } else {
        printf("Invalid flag\n");
    }
    return 0;
}

void strtolower() 
{
    int c;
    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}

void strtoupper() 
{
    int c;
    while ((c = getchar()) != EOF) {
        putchar(toupper(c));
    }
}