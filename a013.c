#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
I 1 
V 5 
X 10 
L 50 
C 100 
D 500 
M 1,000
*/
int r2d(char *s)
{
    char *p=s;
    int v=0;
    while (*p) {
        switch (*p) {
        case 'M':
            v+=(*(p-1) == 'C')? 800:1000;
            break;
        case 'D':
            v+=(*(p-1) == 'C')? 300:500;
            break;
        case 'C':
            v+=(*(p-1) == 'X')? 80:100;
            break;
        case 'L':
            v+=(*(p-1) == 'X')? 30:50;
            break;
        case 'X':
            v+=(*(p-1) == 'I')? 8:10;
            break;
        case 'V':
            v+=(*(p-1) == 'I')? 3:5;
            break;
        case 'I':
            v++;
            break;
        }
        p++;
    }
    return v;
}

void d2r(int n, char *s)
{
    char *p=s;
    if (n==0) {
        strcpy(s, "ZERO");
        return;
    }
    while (n) {
        if (n>=1000) *p++=(char)'M', n-=1000;
        else if (n>=900) *p++=(char)'C', *p++=(char)'M', n-=900;
        else if (n>=500) *p++=(char)'D', n-=500;
        else if (n>=400) *p++=(char)'C', *p++=(char)'D', n-=400;
        else if (n>=100) *p++=(char)'C', n-=100;
        else if (n>=90) *p++=(char)'X', *p++=(char)'C', n-=90;
        else if (n>=50) *p++=(char)'L', n-=50;
        else if (n>=40) *p++=(char)'X', *p++=(char)'L', n-=40;
        else if (n>=10) *p++=(char)'X', n-=10;
        else if (n>=9) *p++=(char)'I', *p++=(char)'X', n-=9;
        else if (n>=5) *p++=(char)'V', n-=5;
        else if (n>=4) *p++=(char)'I', *p++=(char)'V', n-=4;
        else if (n>=1) *p++=(char)'I', n-=1;
    }
    *p=0;
}

int main(void)
{
    char s1[32], s2[32], ans[32];
    int v1, v2, v;
#if 0
    freopen("a013.in", "r", stdin);
#endif
    while (scanf("%s %s", s1, s2)!=EOF) {
        if (s1[0]=='#' || s2[0]=='#') break;
        v1=r2d(s1), v2=r2d(s2), v=abs(v1-v2), d2r(v, ans); /*in case negative, it will be TLE*/
        printf("%s\n", ans);
    }
    return 0;
}
