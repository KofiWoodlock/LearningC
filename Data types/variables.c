// Data types and variables in c
#include <stdio.h>
#include <stdbool.h>

int main() {
	char a = 'A'; // Represents a single character %c
	char b[] = "Bro"; // Represents an array of characters aka a string
	printf("Char: %c\n", a);	
	printf("String: %s\n", b);

	float c = 3.141592; // use 4 bytes of memory (32 bits of precision)
	double d = 3.141592653589793; // Use 8 bytes of memory (64 bits of precision)
	bool isOn = false; // Uses 1 byte of memory 
	char f = 121; // allocates 1 byte of memory and is automatically signed (-128 - +127)
	unsigned char g = 128; // usinged so still uses 1 byte but does not represent numbers (0 - 255)
	printf("char f: %c\n", f);
	printf("char g: %d\n", g);

	// Short ints use 2 bytes of memory 
	signed short int h = 32767; // range from (-32768 to +32767)
	unsigned short int i = 65535; // range from (0 to 65535 or (2^16-1))
	printf("signed short: %d\n", h);
	printf("unsigned short: %d\n", i);

	// regular ints use 4 bytes of memeory 
	signed int j = -2147483648; // range from (-2,147,483,648 to + 2,147,483,647) 
	unsigned int k = 4294967297; // range from (0 to +4294967297 or (2^32-1))

	// long long ints use 8 bytes of memory 
	signed long long  l = -100000000000000000; // range from (-2^64 to 2^63)
	unsigned long long m = 10000000000000000; // range from (0 to 2^64)
	
	// CONSTANTS  a fixed value that cannot be altered by the prgoram during execution
	const float PI = 3.14; 


	return 0;
}
