#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *p, const void *q)
{
    int mm, nn;
    char *pp=(char *)p, *qq=(char *)q;
    if ((*pp=='-')&&(*qq!='-')) return -1;
    if ((*pp!='-')&&(*qq=='-')) return 1;
    mm = strlen(pp), nn = strlen(qq);
    if ((*pp=='-')&&(*qq=='-')) {
        int tmp = strcmp(pp+1, qq+1);
        return (mm==nn)?(tmp*(-1)):(nn-mm);
    }
    if ((mm==1)&&(*pp=='0')) return -1;
    if ((nn==1)&&(*qq=='0')) return 1;
    return (mm==nn)?(strcmp(pp, qq)):(mm-nn);
}

int main(void)
{
    char s[1000][128];
    int i, n;
    /*freopen("a528.in", "r", stdin);*/
    while (scanf("%d\n", &n)==1 && n) {
        for (i=0;i<n;i++) scanf("%s\n", (char *)&s[i]);
        qsort(s, n, 128, cmp);
        for (i=0;i<n;i++) printf("%s\n", (char *)&s[i]);
    }
    return 0;
}
