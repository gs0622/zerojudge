#include <stdio.h>

int main(void)
{
    double f;
    while (scanf("%lf\n", &f) == 1)
        printf("|%.4lf|=%.4lf\n", f, f>0? f:-f);
    return 0;
}

