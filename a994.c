#include <stdio.h>

long long gcd(long long a, long long b)
{
    if (0==b) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
    return (a*b)/gcd(a, b);
}

int main(void)
{
    int m, i, j, bits;
    long long sum, v, n, d[50];
#if 0
    freopen("a994.in", "r", stdin);
#endif
    while (scanf("%lld %d", &n, &m)==2) {
        for (i=0;i<m;i++) scanf("%lld", &d[i]);
        for (i=1, sum=0;i<(1<<m);i++) {
            v=1, bits=0;
            for (j=0;j<m;j++) {
                if (i&(1<<j)) {
                    bits++;
                    v=lcm(v, d[j]);
                    if (v>n) break;
                }
            }
            if (v>n) continue;
            if (bits&1) sum+=n/v; else sum-=n/v;
        }
        printf("%lld\n", n-sum);
    }
    return 0;
}
