#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h> 
#define BUFSIZE 100
#define MAXTOKEN 100
#define NUMBER '0'
#define MAXVAL 100
int getToken(char[]);
void PUSH(double);
double POP();
int m = 0;  //因为判断'-'时可能会取出\n，所以用此变量判断 
int main()
{
    int type; double op2; char s[MAXTOKEN];
    while ((type = getToken(s)) != EOF)
        switch (type)
        {
        case NUMBER: PUSH(atof(s)); break;
        case '+': PUSH(POP() + POP()); break;
        case '*': PUSH(POP() * POP()); break;
        case '-': op2 = POP(); PUSH(POP() - op2); if (m == 1) printf("%d\n", (int)POP());  break;
        case '/': op2 = POP(); PUSH(POP() / op2); break;
        case '\n': printf("%d\n", (int)POP()); break;
        case '%': op2 = (int)POP(); PUSH((int)POP() % (int)op2); break;
        }
    return 0;
}
int sp = 0;
double val[MAXVAL];
void PUSH(double f)
{
    if (sp < MAXVAL) val[sp++] = f;
    else printf("ERROR: Stack Full!");
}
double POP()
{
    if (sp > 0) return val[--sp];
    else { printf("ERROR: Stack Empty!"); return 0.0; }
}
char buf[BUFSIZE];
int bufp = 0;
int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE) printf("ERROR: Buffer Full!");
    else buf[bufp++] = c;
}
int getch();
void ungetch(int);
int getToken(char s[])
{
    int i = 0, c, n;  //n为判断'-'时用来取下一个量 
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = 0;
    if (!isdigit(c) && c != '.' && c != '-') return c;
    if (c == '-') {
        n = getch();
        if (!isdigit(n)) {
            if (n != '\n')return '-';
            else { m = 1; return '-'; }
        }
        c = n;
    }
    else c = getch();
    while (isdigit(s[++i] = c)) c = getch();
    if (c == '.') while (isdigit(s[++i] = c = getch()));
    s[i] = 0;
    if (c != EOF) ungetch(c);
    return NUMBER;
}