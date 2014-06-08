/*uva 340 Master-Mind Hints*/
#include <stdio.h>

int main(void)
{
    int i, j, n, g=1, code[1001], guess[1001];
    /*freopen("d132.in", "r", stdin);*/
    while (scanf("%d", &n)==1 && n) {
        for (i=0;i<n;i++) scanf("%d", &code[i]);
        printf("Game %d:\n", g++);
        while (1) {
            int ss[1001]={0}, gg[1001]={0}, a=0, b=0, s=0;
            for (i=0;i<n;i++) scanf("%d", &guess[i]), s+=guess[i];
            if (0==s) break; /*next case*/
            for (i=0;i<n;i++) {
                if (code[i]==guess[i]) { /*A*/
                    a++, ss[i]=1, gg[i]=1;
                }
            }
            for (i=0;i<n;i++) {
                if (ss[i]) continue;
                for (j=0;j<n;j++) {
                    if (i==j||gg[j]||ss[i]) continue;
                    if (code[i]==guess[j]) {
                        b++, ss[i]=1, gg[j]=1;
                    }
                }
            }
            printf("    (%d,%d)\n", a, b);
        }
    }
    return 0;
}
