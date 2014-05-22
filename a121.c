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
    
int main(int argc, char **argv)
{
    int i, a, b;
    /*freopen("a121.in", "r", stdin);*/
    while (scanf("%d%d", &a, &b)==2) {
        for (i=0;a<=b;a++)
            if (isprime(a)) i++;
        printf("%d\n", i);
    }
    return 0;
}
