#include <stdio.h>

int main(void)
{
    int i;
    while (scanf("%d\n", &i) == 1)
        printf("%d\n", !(i&1));
    return 0;
}

