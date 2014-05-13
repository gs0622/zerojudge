#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *p, const void *q)
{
	int i = *((int *)p), j = *((int *)q);
	return (i-j);
}

int main(void)
{
    int i, n, d[1001];
#if 0
    freopen("a104.in", "r", stdin);
#endif
    while (scanf("%d\n", &n) == 1) {
        for (i=0;i<n;i++) scanf("%d", &d[i]);
        qsort(d, n, 4, cmp);
        for (i=0;i<n;i++) printf("%d ", d[i]);
        printf("\n");
    }
    return 0;
}
