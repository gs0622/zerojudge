#include <stdio.h>

int main(void)
{
    int i;
    while (scanf("%d\n", &i)!=EOF)
        printf("%d\n", (i>0)?i:-i);
    return 0;
}

