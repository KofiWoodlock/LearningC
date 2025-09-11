/* 
Key terms & code:
- Addition operator (+)
    - (x + y) adds x to y
- subtraction operator
    - (x - y) subtracts y from x 
- multiplication operator (*)
    - (x * y) multiplies x with y
- division operator (/)
    - (x / y) divides x by y
- modulus operator (%)
    - (x % y) returns the remainder of x divided by y
- increment operator (++)
    - (x++) or (++x) adds 1 to a variable 
- decrement operator (--)
    - (x--) or (--x) subtracts 1 from a variable 
- Augmented assingment operators
    - Used to replace an assignment statement where a variable is one of the arguments 
- Assingment addition operator (+=)
    - (x += y) reassigns the value of x adding the value of y
- Assignment subtraction operator (-=)
    - (x -= y) reassigns the value of x subtracting the value of y
- Assignment multiplication operator (*=)
    - (x *= y) reassigns the value of x multiplying by the value of y
- Assignment division operator (/=)
    - (x /= y) reassigns the value of x dividing by the value of y
- Assignment modulus operator (%=)
    - (x %= y) reassigns the value of x with the value of x % y
*/

#include <stdio.h>

int main() {

    /* Increment and decrement operators can either be prefix (++n) or postfix (n--)
    their result is the same in which they both either decrement or increment a variable by 1
    but the difference is ++n will increment n before n is used but n++ will use n 
    and then increment it.
    */
    // Example: 
    int x = 0;
    int y = 0;
    for (int i = 0; i < 5; i++) {
        printf("Prefix (x): %d\n", ++x);
        printf("Prefix (y): %d\n", y++);
    }
}