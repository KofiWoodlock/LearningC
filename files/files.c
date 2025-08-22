/*
Files - key terms & code
- strcut FILE 
    - A struct defined in stdio.h to hold information about files 
*/

#include <stdio.h>

int main() {

    // Writing to files
    FILE *pFile = fopen("output.txt", "w");
    char message[] = "Hello World!";

    if (pFile == NULL) {
        printf("Error opening file!");
        return 1;
    }

    fprintf(pFile, "%s", message);
    printf("File write successful.");


    // ALWAYS CLOSE FILE AFTER USE OR YOU GET DATA LEAK
    fclose(pFile);



    return 0;
}