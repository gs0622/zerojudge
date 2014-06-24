/*http://zerojudge.tw/ShowProblem?problemid=d073*/
#include <stdio.h>
int main(void)
{
    int n;
    while (scanf("%d\n", &n)==1) {
        printf("%d\n", (n/3)+((n%3)?1:0));
    }
    return 0;
}

