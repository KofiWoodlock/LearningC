/*
Ternary operator - key code & terms
- Ternary operator ?
    - Shorthand syntax for if-else statements
*/

int max(int x, int y) {
    // Takes two integers and returns larger one
    return (x > y) ? x : y;
}

int main() {
    printf("%d", max(5, 6));
}