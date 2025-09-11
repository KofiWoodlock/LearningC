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

void rmchar(char s[], char c);
void strcat1(char s[], char t[]);
void squeeze(char s[], char t[]);

int main() {

    char a[] = "01012340101";
    char b[] = "234";
    printf("a before: %s\n", a);
    squeeze(a, b);
    printf("a after: %s\n", a);

    return 0;

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

    char t[] = "01222101022202122";
    printf("T before: %s\n" , t);
    rmchar(t, '2');
    printf("T after: %s\n" , t);

    char m[64] = "Hello";
    char n[] = " World!";
    strcat1(m, n);

    printf("Output: %s\n", m);
}

/* Removes all instances of character c from string s*/
void rmchar(char s[], char c) {

    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) 
        // non-c char copied into s[j] then j is incremented 
            s[j++] = s[i];
    }
    s[j] = '\0';
}

/* Concatenates string t with string s - s must be big enough to hold t*/
void strcat1(char s[], char t[]) { 
    int i, j;
    i = j = 0;
    while (s[i] != '\0') // find end of s
        i++;
    while ((s[i++] = t[j++]) != '\0'); // copy t
}


/* Removes any instance of any char in t from s */
void squeeze(char s[], char t[]) {
    int i, j, k;
    k = 0;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; s[i] != t[j] && t[j] != '\0'; j++)
            ;
        if (t[j] =='\0')
            s[k++] = s[i];
        }

    s[k] = '\0';
}
