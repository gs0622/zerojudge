#include <stdio.h>
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
    while (p && *p) {
        switch (*p) {
        case 'M': v+=1000; break;
        case 'D': v+=500; break;
        case 'C':
            if (*(s+1) == 'M') v+=900, p++;
            else if (*(s+1) == 'D') v+=400, p++;
            else v+=100;
            break;
        case 'L':
            if (*(s+1) == 'M') v+=950, p++;
            else if (*(s+1) == 'D') v+=450, p++;
            else v+=50;
            break;
        case 'X':
            if (*(s+1) == 'M') v+=990, p++;
            else if (*(s+1) == 'D') v+=490, p++;
            else if (*(s+1) == 'C') v+=90, p++;
            else if (*(s+1) == 'L') v+=40, p++;
            else v+=10;
            break;
        case 'V':
            if (*(s+1) == 'M') v+=995, p++;
            else if (*(s+1) == 'D') v+=495, p++;
            else if (*(s+1) == 'C') v+=95, p++;
            else if (*(s+1) == 'L') v+=45, p++;
            else v+=5;
            break;
        case 'I':
            if (*(s+1) == 'M') v+=999, p++;
            else if (*(s+1) == 'D') v+=499, p++;
            else if (*(s+1) == 'C') v+=99, p++;
            else if (*(s+1) == 'L') v+=49, p++;
            else if (*(s+1) == 'X') v+=9, p++;
            else if (*(s+1) == 'V') v+=4, p++;
            else v+=1;
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
    while (n && p) {
        if (n>=1000) *p++=(char)'M', n-=1000;
        else if (n>=999) *p++=(char)'I', *p++=(char)'M', n-=999;
        else if (n>=900) *p++=(char)'C', *p++=(char)'M', n-=900;
        else if (n>=500) *p++=(char)'D', n-=500;
        else if (n>=490) *p++=(char)'I', *p++=(char)'D', n-=499;
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
        *p=0;
    }
}

int main(void)
{
    char s1[32], s2[32];
    int v1, v2, v;
    /*freopen("a013.in", "r", stdin);*/
    while (scanf("%s %s\n", s1, s2)!=EOF && s1[0]!='#') {
        char ans[32]={};
        v1=r2d(s1), v2=r2d(s2), v=v1-v2, d2r(v, ans);
        printf("%s\n", ans);
        /*printf("%d\n", v);*/
    }
    return 0;
}
