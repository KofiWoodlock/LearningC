/* 
Key code & terms
- Recursion 
    - The process of a function calling itself in the function body
*/

#include <stdio.h>

int sumn(int n);

int main() {

    int result;

    result = sumn(100);
    printf("Result of sumn: %d\n", result);

    return 0;
}

/* Sums the natural numbers from 1 to n*/
int sumn(int n) {
    // Computes 1 + 2 + 3 + ... + n
    int x, sum, rval;

    if (n <= 1) return 1;
    x = n - 1;
    sum = sumn(x);
    rval = n + sum;
    return rval;
}