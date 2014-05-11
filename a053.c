#include <stdio.h>

int main(void)
{
    int n, s/*score*/;
#if 0
    freopen("a053.in", "r", stdin);
#endif  
    while (scanf("%d", &n)==1 && n>=0 && n<=100) {
        s = 0;
        if (n<=10) s+=n*6;
        else {
            if (n>=11 && n<=20) s=60, s+=2*(n-10);
            else if (n>=21 && n<40) s=80, s+=n-20;
        }
        if (n>=40) s=100;
        printf("%d\n", s);
    }
    return 0;
}
