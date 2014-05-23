#include <stdio.h>

int main(void)
{
    int n, m, i, s;
    while (scanf("%d%d", &n, &m)==2) {
        for (i=n,s=0;;i++) {
            s+=i;
            if (s > m) break;
        }
        printf("%d\n", i-n+1    );
    }
    return 0;
}
