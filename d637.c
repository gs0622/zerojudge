/*http://zerojudge.tw/ShowProblem?problemid=d637*/
#include <stdio.h>
#define MAX(a, b)   ((a)>(b)?(a):(b))
typedef struct {
    int vol;
    int full;
} duck;
duck d[10000]={};
int c[101];
int knapsack(int n, int vol)
{
    int i, j, v, f;
    for (i=0;i<sizeof(c)/sizeof(int);i++) c[i]=0;
    for (i=0;i<n;i++) {
        v = d[i].vol, f = d[i].full;
        for (j=vol;j-v>=0;j--) {
            c[j] = MAX(c[j], c[j-v]+f);
            /*printf("%d: c[%d]=%d\n", i, j, c[j]);*/
        }
    }
    return c[vol];
}
int main(void)
{
    int n, i;
    scanf("%d\n", &n);
    for (i=0;i<n;i++) scanf("%d %d\n", &d[i].vol, &d[i].full);
    printf("%d\n", knapsack(n, 100));
    return 0;
}

