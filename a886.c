#include <stdio.h>
#include <string.h>

int main(void)
{
    int t, n, m, k, f[52][52], a, b, c, d;
    while (scanf("%d\n", &t)==1 && t<=100) {
        for (a=0;a<t;a++) {
            scanf("%d %d %d\n", &m, &n, &k);
            memset((void *)f, 0, sizeof(f));
            for (b=1;b<=m;b++) {
                for (c=1;c<=n;c++) {
                    scanf("%d\n", &d);
                    if (d==1) {
                        f[b][c] = 1;
                        f[b-1][c] = f[b+1][c] = 1;
                        f[b][c-1] = f[b][c+1] = 1;
                    }
                }
            }
            d = m*n*k;
            for (b=1;b<=m;b++) {
                for (c=1;c<=n;c++) {
                    if (f[b][c]) d-=3;
                }
            }
            printf("%d\n", d);
       }
    }
    return 0;
}


