/*http://zerojudge.tw/ShowProblem?problemid=a005*/
#include <stdio.h>

int main(void)
{
    char buf[1024], *p = buf;
    int i, j, t, d[20][5], arithmetical, dist, ratio;
    while (scanf("%d\n", &t) == 1) {
        for (i=0;i<t;i++) {
            arithmetical = 0;
            for (j=0;j<4;j++) {
                scanf("%d", &d[i][j]);
                p+=sprintf(p, "%d ",d[i][j]);
            }
            if ((d[i][3]-d[i][2])==
                (d[i][2]-d[i][1])) {
                    arithmetical = 1;
                    dist = d[i][3]-d[i][2];
            }
            else
                ratio = d[i][3]/d[i][2];
            d[i][4] = (arithmetical)? d[i][3]+dist: d[i][3]*ratio;
            p+=sprintf(p, "%d\n",d[i][4]);
        }
        printf("%s", buf);
    }
    return 0;
}

