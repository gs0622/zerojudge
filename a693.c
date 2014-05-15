#include <stdio.h>

int main(void)
{
    int n, m, i, l, r;
#if 0
    freopen("a693.in", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) != EOF) {
        int f[100001]={}, d[100001]={};
        for (i=1;i<=n;i++) scanf("%d", &f[i]);
        for (i=2, d[1]=f[1];i<=n;i++) d[i]+=d[i-1]+f[i];
        for (i=0;i<m;i++) {
        if (scanf("%d %d", &l, &r)==2) printf("%d\n", d[r]-d[l-1]);
        }
    }
    return 0;
}
