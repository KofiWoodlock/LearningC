/*
Files - key terms & code
- strcut FILE 
    - A struct defined in stdio.h to hold information about files 
*/

#include <stdio.h>

int wfile(char path[], char message[]);

int main() {

    // Writing to files
    FILE *pFile = fopen("output.txt", "w"); // This is a relative path
    char message[] = "Hello World!";

    if (pFile == NULL) {
        printf("Error opening file!");
        return 1;
    }

    fprintf(pFile, "%s", message);
    printf("File write successful.\n");

    // ALWAYS CLOSE FILE AFTER USE OR YOU GET DATA LEAK
    fclose(pFile);

    // Writing to a file using an absolute path
    char filePath[] = "C:\\Users\\44759\\Desktop\\hello.txt";

    wfile(filePath, "This is my desktop");

    return 0;
}

int wfile(char path[], char message[]) {
    FILE *pfile = fopen(path, "w");
    if (pfile == NULL) {
        printf("Error when loading file.\n");
        return 1;
    }

    fprintf(pfile, "%s", message);
    printf("File write successful.\n");
    return 0;
}