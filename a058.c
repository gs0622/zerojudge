#include <stdio.h>

int main(void)
{
    int i, n, k;
#if 0
    freopen("a058.in", "r", stdin);
#endif
    while (scanf("%d", &n)!=EOF) {
        int mod[3]={};
        for (i=0;i<n;i++) {
            scanf("%d", &k), mod[k%=3]++;
        }
        printf("%d %d %d\n", mod[0], mod[1], mod[2]);
    }
    return 0;
}
