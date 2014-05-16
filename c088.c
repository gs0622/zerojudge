#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int c[32768]; /*counting table*/

static void factorize(int n)
{
    int d=2;
    while (d<=n) { /*prime factorization*/
        if (n%d==0) n/=d, c[d]++;
        else d+=(d==2)?1:2;
    }
}

int main(void)
{
    int prime, pow, x, i, space;
    char s[1024], *p, *q;
#if 0
    freopen("c088.in", "r", stdin);
#endif
    while (gets(s) && strcmp(s,"0")) {
        p=s, x=1, space=0, memset(c, 0, sizeof(c));
        while (p && (q = strsep(&p, " "))) {
            prime=atoi(q);
            pow=p? atoi(q = strsep(&p, " ")):1;
            while (pow--) x*=prime;
        }
        factorize(x-1);
        for (i=32767;i>2;i-=2) /*all primes are odd except 2 */
            if (c[i]) printf("%s%d %d", space?" ":"", i, c[i]), space=1;
        if (c[2]) printf("%s2 %d", space?" ":"", c[2]);
        printf("\n");
    }
    return 0;
}
