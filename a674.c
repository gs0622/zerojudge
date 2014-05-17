#include <stdio.h>
#include <string.h>

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)<(b)?(a):(b)) 

int main(void)
{
    int c, s ,q, i, j, k, l=1, d[101][101];
#if 0
    freopen("a674.in", "r", stdin);
#endif
    while (scanf("%d %d %d", &c, &s, &q)==3 && c+s+q) {
        for (i=1;i<=c;i++)
            for (j=1;j<=c;j++) d[i][j] = 0xfff/*4095*/;
        while(s--) scanf("%d %d %d", &i, &j, &k), d[i][j]=d[j][i]=k;/*undirected*/
        for (k=1;k<=c;k++)
            for (i=1;i<=c;i++)
                for (j=1;j<=c;j++)
                    d[i][j] = MIN(d[i][j], MAX(d[i][k], d[k][j]));
        printf("Case #%d\n", l++);
        for (i=0;i<q;i++) {
            scanf("%d %d", &j, &k);
            if (d[j][k] != 0xfff) printf("%d\n", d[j][k]);
            else printf("no path\n");
        }
        printf("\n");
    }
    return 0;
}
