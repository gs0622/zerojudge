#include <stdio.h>

int main(void)
{
    int n, m, i, j, x1, y1, x2, y2;
#if 0
    freopen("a694.in", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) != EOF) {
        int f[501][501]={}, d[501][501]={};
        for (j=1;j<=n;j++) {
            for (i=1;i<=n;i++) {
                scanf("%d", &f[i][j]);
            }
        }
        for (j=1;j<=n;j++) {
            for (i=1;i<=n;i++) {
                d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+f[i][j];
                /*printf("%.2d ", d[i][j]);*/
            }
            /*puts("");*/
        }
        for (i=0;i<m;i++) {
            if (scanf("%d %d %d %d", &x1, &y1, &x2, &y2)==4) {
                printf("%d\n", d[y2][x2]-d[y2][x1-1]-d[y1-1][x2]+d[y1-1][x1-1]);
            }
        }
    }
    return 0;
}
