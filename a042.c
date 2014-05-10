#include <stdio.h>

int main(void)
{
    int n;
#if 0
    freopen("a042.in", "r", stdin);
#endif
    while (scanf("%d\n", &n) != EOF)
        printf("%d\n", n*n-n+2);
    return 0;
}

