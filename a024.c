/*http://zerojudge.tw/ShowProblem?problemid=a024*/
#include <stdio.h>

/*greatest common divisor*/
int gcd(int a, int b)
{
    if (0==b) return a;
    return gcd(b, a%b);
}

int main(void)
{
    int a, b;
    while (scanf("%d %d\n", &a, &b) == 2) {
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
