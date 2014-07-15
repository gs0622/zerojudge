#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[8], password[6];
    int i;
    while (scanf("%s", str)!=EOF) {
        /*printf("%s\n", str);*/
        for (i=0;i<6;i++) {
            password[i]=abs(str[i+1]-str[i]);
            printf("%d", password[i]);
        }
        printf("\n");
    }
    return 0;
}

