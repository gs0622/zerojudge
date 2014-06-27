#include <stdio.h>

int main(void)
{
    int n, m, i, j, x1, y1, x2, y2;
#if 1
    freopen("a694.in", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) != EOF) {
        int f[501][501]={}, d[501][501]={};
        for (i=1;i<=n;i++) {
            for (j=1;j<=n;j++) {
                scanf("%d", &f[i][j]);
            }
        }
#if 1
        for (i=1;i<=n;i++) {
            //d[i][0]+=d[i-1][n];
            //d[i][0]+=d[i-1][1];
            for (j=1;j<=n;j++) {
                d[i][j]+=d[i-1][j]+d[i][j-1]+f[i][j];
                printf("%.2d ", d[i][j]);
            }
            puts("");
        }
#endif
        for (i=0;i<m;i++) {
            if (scanf("%d %d %d %d", &x1, &y1, &x2, &y2)==4) {
                printf("%d\n", d[x2][y2]-d[x1][y1]+f[x1][y1]);
            }
        }
    }
    return 0;
}
