/*http://zerojudge.tw/ShowProblem?problemid=a006*/
#include <stdio.h>
#include <math.h>

/*hint: http://en.wikipedia.org/wiki/Quadratic_equation*/
int main(void)
{
    int a, b, c, t, r[2];
    double u;

    while (scanf("%d %d %d\n", &a, &b, &c) == 3) {
        t = b*b-(4*a*c);
        if (0<t) {
            u = sqrt(t);
            r[0] = ((-1)*b + (int)u)/(2*a);
            r[1] = ((-1)*b - (int)u)/(2*a);
            printf("Two different roots x1=%d , x2=%d\n", r[0], r[1]);
        } else if (t==0){
            printf("Two same roots x=%d\n", (-1)*b/(2*a));
        } else {
            printf("No real root\n");
        }
    }
    return 0;
}
