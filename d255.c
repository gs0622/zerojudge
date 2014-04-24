/*http://zerojudge.tw/ShowProblem?problemid=d255*/
#include <stdio.h>

int gcd(int a, int b)
{
    if (0==b) return a;
    return gcd(b, a%b);
}

int main(void)
{
    int n, i, j, g;
    while (scanf("%d\n", &n)==1 && n>0 && n<501) {
        g=0;
        for (i=1;i<n;i++) {
            for (j=i+1;j<=n;j++) g+=gcd(i,j);
        }
        printf("%d\n", g);
    }
    return 0;
}
