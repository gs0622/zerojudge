#include <stdio.h>

int main(void)
{
    int a, b, N, i;
    while (scanf("%d %d %d\n", &a, &b, &N) == 3) {
        printf("%d.", a/b);
        for (i=0; i<N; i++, a=((a%b)*10)%b) {
            printf("%d", (a%b)*10/b);
        }
        printf("\n");
    }
    return 0;
}
