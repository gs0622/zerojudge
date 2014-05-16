#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int c[32768];
static char s[1024], t[16];
static void factorize(int n)
{
    int d=2;
    while (d<=n) { /*prime factorization*/
        if (n%d==0) n/=d, c[d]++;
        else d+=(d==2)?1:2;
        /*if (d>181) printf("[%s]\n", s);*/
    }
}

int main(void)
{
    int prime, pow, x, i, j;
    char *p, *q;
#if 0
    freopen("c088.in", "r", stdin);
#endif
    while (gets(s) && strcmp(s,"0")) {
#if 0
        x=1, memset(c, 0, sizeof(c));
        for (i=0;s[i];i++) {
            memset(t, 0, 16), j=0;
            while (s[i]!=' ') t[j++]=s[i++];
            prime=atoi(t);
            memset(t, 0, sizeof(t)), i++, j=0;
            while (s[i]!=' '&&s[i]!='\0') t[j++]=s[i++];
            pow=atoi(t);
            while (pow--) x*=prime;
            if (s[i]=='\0') break;
        }
#else
        p=s, x=1, memset(c, 0, sizeof(c));
        while (p && (q = strsep(&p, " "))) {
            prime=atoi(q);
            pow=p? atoi(q = strsep(&p, " ")):1;
            while (pow--) x*=prime;
        }
#endif
        factorize(x-1);
        for (i=(sizeof(c)/sizeof(int)-1);i>=2;i--)
            if (c[i]) printf("%d %d ", i, c[i]);
        printf("\n");
        memset(s, 0, sizeof(s));
    }
    return 0;
}
