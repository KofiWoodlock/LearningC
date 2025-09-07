// Data types and variables in c
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define CHAR_SIZE_BITS sizeof(char) * 8
#define SHORT_SIZE_BITS sizeof(short) * 8
#define INT_SIZE_BITS sizeof(int) * 8
#define LONG_LONG_SIZE_BITS sizeof(long long) * 8

int main() {
	char a = 'A'; // Represents a single character %c
	char b[] = "Bro"; // Represents an array of characters aka a string
	// printf("Char: %c\n", a);	
	// printf("String: %s\n", b);

	float c = 3.141592; // use 4 bytes of memory (32 bits of precision)
	double d = 3.141592653589793; // Use 8 bytes of memory (64 bits of precision)
	bool isOn = false; // Uses 1 byte of memory 
	char f = 121; // allocates 1 byte of memory and is automatically signed (-128 - +127)
	unsigned char g = 128; // usinged so still uses 1 byte but does not represent numbers (0 - 255)
	// printf("char f: %c\n", f);
	// printf("char g: %d\n", g);

	// Short ints use 2 bytes of memory 
	signed short int h = 32767; // range from (-32768 to +32767)
	unsigned short int i = 65535; // range from (0 to 65535 or (2^16-1))
	// printf("signed short: %d\n", h);
	// printf("unsigned short: %d\n", i);

	// regular ints use 4 bytes of memeory 
	signed int j = -2147483648; // range from (-2,147,483,648 to + 2,147,483,647) 
	unsigned int k = 4294967295; // range from (0 to +4294967297 or (2^32-1))

	// long long ints use 8 bytes of memory 
	signed long long  l = -100000000000000000; // range from (-2^64 to 2^63)
	unsigned long long m = 10000000000000000; // range from (0 to 2^64)
	
	// CONSTANTS  a fixed value that cannot be altered by the prgoram during execution
	const float PI = 3.14; 

	// Register variables - A variable that is stored within the CPU registers instead of main memory 	
	register int x;
	register char c;

	printf("signed char:\n- uses %d byte(s) of memory\n- ranges from %.0f to %.0f\n", sizeof(char), -pow(2, CHAR_SIZE_BITS-1), pow(2, CHAR_SIZE_BITS-1)-1);
	printf("\n");
	printf("unsigned char:\n- uses %d byte(s) of memory\n- ranges from %.0f to %.0f\n", sizeof(char), 0, pow(2, CHAR_SIZE_BITS)-1);
	printf("\n");
	printf("signed short:\n- uses %d byte(s) of memory\n- ranges from %0.f to %0.f\n", sizeof(short), -pow(2, SHORT_SIZE_BITS-1), pow(2, SHORT_SIZE_BITS-1)-1);
	printf("\n");
	printf("unsigned short:\n- uses %d byte(s) of memory\n- ranges from %0.f to %0.f\n", sizeof(short), 0, pow(2, SHORT_SIZE_BITS)-1);
	printf("\n");
	printf("signed int:\n- uses %d byte(s) of memory\n- ranges from %0.f to %0.f\n", sizeof(int), -pow(2, INT_SIZE_BITS-1), pow(2, INT_SIZE_BITS-1)-1);
	printf("\n");
	printf("unsigned int:\n- uses %d byte(s) of memory\n- ranges from %0.f to %0.f\n", sizeof(int), 0, pow(2, INT_SIZE_BITS)-1);
	printf("\n");
	printf("signed long long:\n- uses %d byte(s) of memory\n- ranges from %0.f to %0.f\n", sizeof(long long), -pow(2, LONG_LONG_SIZE_BITS-1), pow(2, LONG_LONG_SIZE_BITS-1)-1);
	printf("\n");
	printf("unsigned long long:\n- uses %d byte(s) of memory\n- ranges from %0.f to %0.f\n", sizeof(long long), 0, pow(2, LONG_LONG_SIZE_BITS)-1);
	printf("\n");
	printf("float:\n- uses %d bytes of memory\n", sizeof(float));
	printf("\n");
	printf("double:\n- uses %d bytes of memory\n", sizeof(double));
	
	return 0;
}
