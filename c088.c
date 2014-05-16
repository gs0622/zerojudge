#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int c[256];
static void factorize(int n)
{
    int d=2;
    while (d<=n) { /*prime factorization*/
        if (n%d==0) n/=d, c[d]++;
        else d+=(d==2)?1:2;
        if (d>181) printf("d=%d\n", d);
    }
}

int main(void)
{
    char s[1024], *p, *q;
    int prime, pow, x, i;
#if 0
    freopen("c088.in", "r", stdin);
#endif
    while (gets(s) && s[0]!='0') {
        p=s, x=1, memset(c, 0, sizeof(c));
        while ((q = strsep(&p, " "))!=NULL) {
            prime=atoi(q), pow=q? atoi(q = strsep(&p, " ")):0;
            while (pow--) x*=prime;
        }
        factorize(x-1);
        for (i=(sizeof(c)/sizeof(int)-1);i>=2;i--)
            if (c[i]) printf("%s%d %d", (i==0)?"":" ", i, c[i]);
        puts("");
    }
    return 0;
}
