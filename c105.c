#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { int x; int y; } coo_t;
coo_t coo[700]/*coordination*/, slo[700]/*sloppe*/, tmp;

static int cmp(const void *p, const void *q)
{
	coo_t *a=(coo_t *)p, *b=(coo_t *)q;
	if (a->y != b->y) return (a->y - b->y);
    return (a->x - b->x);
}

static int gcd(int a, int b)
{
    if (0==b) return a;
    return gcd(b, a%b);
}

int main(void)
{
    char s[1024];
    int t, n, i, j, k, l, max, cnt;
#if 0
    freopen("c105.in", "r", stdin);
#endif
    scanf("%d", &t);
    getchar(), getchar();
    while (t--) {
        n=0, max=1, memset(slo, 0, sizeof(slo));
        while (gets(s)) {
            if (s[0]=='\0') break; /*next case*/
            sscanf(s, "%d %d\n", &coo[n].x, &coo[n].y), n++;
        }
        qsort(coo, n, sizeof(coo_t), cmp);
        for (i=0;i<n;i++) { /*pivot turn from lowest coordination*/
            for (j=i+1,k=0;j<n;j++, k++) {
                slo[k].x=coo[j].x-coo[i].x, slo[k].y=coo[j].y-coo[i].y;
                l = gcd(slo[k].x, slo[k].y);
                slo[k].x/=l, slo[k].y/=l;
            }
            qsort(slo, k, sizeof(coo_t), cmp);
            /*for (j=0;j<k;j++) printf("m%d: %d %d\n", j, slo[j].x, slo[j].y);*/
            for (j=1,cnt=1,tmp=slo[0];j<k;j++) {
                if (tmp.x==slo[j].x && tmp.y==slo[j].y) cnt++;
                else {
                    if (cnt>max) max=cnt;
                    cnt=1, tmp=slo[j];
                }
            }
            if (cnt>max) max=cnt;
        }
        printf("%d\n", max+1);
        if (t) puts("");
    }
    return 0;
}
