/*http://zerojudge.tw/ShowProblem?problemid=d550*/
#include <stdio.h>
#include <stdlib.h>

struct data {
    int c[200];
} r[10000];

int n, m;

static int cmp(const void *p, const void *q)
{
    int i;
    struct data *a, *b;
    a = (struct data *)p;
    b = (struct data *)q;
    for (i=0;i<m;i++) {
        if (a->c[i] > b->c[i]) return 1;  /*greater*/
        if (a->c[i] < b->c[i]) return -1; /*less*/
    }
    return 0 /*match*/;
}

int main(void)
{
    int i, j;
    while (scanf("%d %d\n", &n, &m) == 2) {
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++) scanf("%d", &r[i].c[j]);
        }
        qsort(r, n, sizeof(int)*200, cmp);
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++) printf("%d ", r[i].c[j]);
            printf("\n");
        }
    }
    return 0;
}
