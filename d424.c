/*http://zerojudge.tw/ShowProblem?problemid=d424*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i=0, j, l, h, r, sky[10000+1], max_r=0, skyline=0;
    memset((void *)sky, 0, sizeof(sky));
    while (scanf("%d %d %d\n", &l, &h, &r) == 3) {
        for (i=l; i<r; i++) {
            if (h>sky[i]) sky[i] = h;
            if (r>max_r) max_r = r;
        }
    }
#if 0
    for (i=0; i<max_r+1; i++) printf("%.2d ", sky[i]);
    printf("\n");
#endif
    for (i=0; i<max_r; i++) {
        if (skyline==sky[i]) continue;
        skyline = sky[i];
        printf("%d %d ", i, skyline);
    }
    printf("%d 0\n", max_r);
    return 0;
}
