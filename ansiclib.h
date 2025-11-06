#ifndef ANSICLIB_H
#define ANSICLIB_H

/*
ansiclib.h
Utility header for ansi C 2nd edition functions
*/

int strtoint(char s[]);
int chartoint(char n);
double strtofloat(char s[]);
int hextoint(char h[]);
int getch(void);
void ungetch(int c);

#endif /* ANSICLIB_H */