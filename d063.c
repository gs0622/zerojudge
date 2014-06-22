/*http://zerojudge.tw/ShowProblem?problemid=d063*/
#include <stdio.h>
int main(void)
{
    unsigned int i;
    while (scanf("%u\n", &i)==1) {
        printf("%u\n", !(i&1));
    }
    return 0;
}

