#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[16];
    int i, t, m;
#if 0
    freopen("a149.in", "r", stdin);
#endif
    while (scanf("%d\n", &t)==1 && t) {
        while (t--) {
            char c[2]={};
            scanf("%s", s);
            for (i=0,m=1;i<strlen(s);i++) c[0]=s[i], m*=atoi(c);
            printf ("%d\n", m);
        }
    }
    return 0;
}