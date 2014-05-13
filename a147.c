#include <stdio.h>

int main(void)
{
    int i, n;
#if 0
    freopen("a147.in", "r", stdin);
#endif
    while (scanf("%d\n", &n)==1 && n) {
        for (i=0;i<n;i++) if (i%7) printf("%d ", i); 
        printf("\n");
    }
    return 0;
}
