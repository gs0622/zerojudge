/*http://zerojudge.tw/ShowProblem?problemid=a007*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
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
        if (isprime(a))
            printf("\u8CEA\u6578\n");
        else
            printf("\u975E\u8CEA\u6578\n");
    }
    return 0;
}
