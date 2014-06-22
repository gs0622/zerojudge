/*http://zerojudge.tw/ShowProblem?problemid=a414
 tags: bit, add, carry
*/
#include <stdio.h>
int main(void)
{
    unsigned int n, m, bits, c;
    while (scanf("%d\n", &n) == 1) {
        if (0==n) break;
        m=n+1, bits=n^m, c=-1;
        while (bits) c++, bits>>=1;
        printf("%d\n", c);
    }
    return 0;
}

