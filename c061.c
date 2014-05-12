#include <stdio.h>

int main(void)
{
    int n, m, i;
    long long c; /*avoid overflow*/
#if 0
    freopen("c061.in", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m)==2 && n+m /*as n>0&&m>0*/ && n>=m) {
        if (m>n/2) m=n-m;/*Cnm = Cn(n-m)*/
        for (i=0,c=1; i<m; i++) c*=n-i, c/=(1+i); /*reduced common (n-m)!*/
        printf("%lld\n", c);
    }
    return 0;
}

