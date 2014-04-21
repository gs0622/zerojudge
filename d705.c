/*http://zerojudge.tw/ShowProblem?problemid=d705*/
#include <stdio.h>
#include <math.h>

int isprime(int n)
{
    int maxdiv;
    int div = 5;
    if (n<2) return 0; /*false*/
    if ((n==2)||(n==3)) return 1; /*true*/
    if ((n%2==0)||(n%3==0)) return 0;
    maxdiv = (int)(sqrt((double)n))+1;
    div = 5;
    while (div<maxdiv) {
        if ((n%div==0)||(n%(div+2)==0)) return 0;
        div+=6;
    }
    return 1;
}

int main(void)
{
    int a;
    while (scanf("%d\n", &a) == 1) {
        if (0==a) break;
        if (isprime(a))
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
