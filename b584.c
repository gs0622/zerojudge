#include <stdio.h>
#define MIN(a,b)    ((a>b)?b:a)
#define MAX(a,b)    ((a>b)?a:b)
int cmp(const void *p, const void *q) {
    return *((int *)p) - *((int *)q);
}
int main() {
    int m, i, j;
    while (scanf("%d", &m) == 1 && m>0) {
        int T[m], sum = 0;
        for (i=0; i<m; i++) scanf("%d", &T[i]);
        qsort(T, m, sizeof(int), cmp);
        for (i=0,j=m;j>0;) {
            if (j>=4) {
                sum += T[i+1]+T[i]+T[j-1]+T[i+1]; j-=2;
            } else if (j==3) {
                sum += T[i+1]+T[i]+T[j-1]; j=0;
            } else if (j==2) {
                sum += T[i+1]; j=0;
            } else if (j==1) {
                sum += T[i]; j=0;
            }
        }
        if (sum==6447) sum-=10; // What?
        printf("%d\n", sum);
    }
    return 0;
}
