/*http://zerojudge.tw/ShowProblem?problemid=d049*/
#include <stdio.h>
int main(void)
{
    unsigned int y;
    while (scanf("%d\n", &y)==1 && y>=1912) {
        printf("%d\n", y-1911);
    }
    return 0;
}

