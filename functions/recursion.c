/* 
Key code & terms
- Recursion 
    - The process of a function calling itself in the function body
*/

#include <stdio.h>

int sumn(int n);
void printd(int n);
void quicksort(int v[], int left, int right);
void swap(int v[], int i, int j);
int decimaltostr(int n, char s[], int i);

int main() {

    int result;

    result = sumn(100);
    printf("Result of sumn: %d\n", result);
    int number = 123;
    printd(number);
    printf("\n");
    printf("Converting int to str using recusrion\n");
    int x = 123;
    char output[7]; 
    decimaltostr(x, output, 0);
    printf("\"%s\"", output);

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

/* print n in decimal string format */
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

/* sorts integer array v into ascending order */
void quicksort(int v[], int left, int right) {

    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right) /* Do nothing if arr has <2 elements */
        return;
    swap(v, left, (left + right)/2); /* Move partition element to v[0] */
    last = left;
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last); /* Restore partition element */
    quicksort(v, left, last-1);
    quicksort(v, last+1, right);
}

/* interchange v[i] and v[j] */
void swap(int v[], int i, int j) {

    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;

}

/* Converts integer n to string representation */
int decimaltostr(int n, char s[], int i) {

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    } 
    if (n / 10)
        i = decimaltostr(n / 10, s, i);
    s[i++] = (n % 10 + '0');   
    s[i] = '\0';
    return i;
}
