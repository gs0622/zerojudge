#include <stdio.h>

#define unlikely(x)     __builtin_expect((x),0)

int main(void)
{
    int n, div, old, first, pow;
    while (scanf("%d", &n) && n>1 && n<=1000000) {
        div=2, old=0, first = 1;
        while (n>=div) {
            if (n%div==0) {
                if (unlikely(first)) {
                    printf("%d", div);
                    first=0, pow=1;
                } else {
                    if (old!=div) {
                        if (pow > 1) printf("^%d", pow), pow=1;
                        printf(" * %d" , div);
                    } else pow++;
                }
                old=div, n/=div;
            } else div++;
        }
        if (pow > 1) printf("^%d", pow);
        printf("\n");
    }
    return 0;
}
