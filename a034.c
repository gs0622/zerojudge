/*http://zerojudge.tw/ShowProblem?problemid=a034*/
#include <stdio.h>

int main(void)
{
    unsigned int x, y, z;
    while (scanf("%u\n", &x) == 1) {
        y = (1<<31);
        z = 0;
        while (y) {
            if (x & y) {
                z = 1; /*MSB hit*/
                printf("1");
            } else {
                if (z) printf("0");
            }
            y >>= 1;
        }
        printf("\n");
    }
    return 0;
}
