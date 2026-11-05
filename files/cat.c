#include <stdio.h> 

/* Copy program of the unix util function cat */
int main(int argc, char const *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);

    if (argc == 1) /* no argument passed copy stdin */
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: failed to open %s\n", *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    return 0;
}


void filecopy(FILE *pfilein, FILE *pfileout) {
    int c;

    while ((c = getc(pfilein)) != EOF)
        putc(c, pfileout);
}

