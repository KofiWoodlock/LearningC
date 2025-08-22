/*
Files - key terms & code
- strcut FILE 
    - A struct defined in stdio.h to hold information about files 
- buffer
    - Temporarily stores data read from an input stream
*/

#include <stdio.h>

int wfile(char path[], char message[]);
int rfile(char path[]);
int apfile(char path[], char message[]);
FILE* openfile(char path[], char mode[]);

int main() {

    // // Writing to files
    // FILE *pFile = fopen("output.txt", "w"); // This is a relative path
    // char message[] = "Hello World!";

    // if (pFile == NULL) {
    //     printf("Error opening file!");
    //     return 1;
    // }

    // fprintf(pFile, "%s", message);
    // printf("File write successful.\n");

    // // ALWAYS CLOSE FILE AFTER USE OR YOU GET DATA LEAK
    // fclose(pFile);

    // Writing to a file using an absolute path
    char filePath[] = "C:\\Users\\44759\\Desktop\\hello.txt";

    // wfile(filePath, "This is my desktop");

    rfile(filePath);
    
    return 0;
}

/* Writes message to the file specified in the path*/
int wfile(char path[], char message[]) {
    FILE *pfile = fopen(path, "w");
    if (pfile == NULL) {
        printf("Error when loading file.\n");
        return 1;
    }

    fprintf(pfile, "%s", message);
    printf("File write successful.\n");
    fclose(pfile);
    return 0;
}

/* Reads and prints the contents of a file*/
int rfile(char path[]) {

    FILE *pf = openfile(path, "r");

    if (pf == NULL) {
        printf("Error reading file");
        return 1;
    }
    // Initialise buffer to be 1kB 
    char buf[1024] = {0}; // clear all values by setting to 0

    while (fgets(buf, sizeof(buf), pf) != NULL)
        printf("%s", buf); // print contents of file
    fclose(pf);
    return 0;
}

/*Appends message to the end of a file*/
int apfile(char path[], char message[]) {

    FILE *pf = openfile(path, "a");

    if (pf == NULL) {
        printf("Error loading file");
        return 1;
    }
    fprintf(pf, message);
    printf("Successfully appended to file");
    fclose(pf);
    return 0;
}

FILE* openfile(char path[], char mode[]) {
    return fopen(path, mode);
}