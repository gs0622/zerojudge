#include <stdio.h>
#include <math.h>

int main(void)
{
    double n, p;
    while (scanf("%lf\n%lf\n", &n, &p) == 2) {
        printf("%.0lf\n", pow(p, 1/n));
    }
    return 0;
}
