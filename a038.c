/*http://zerojudge.tw/ShowProblem?problemid=a038*/
#include <stdio.h>

int main(void)
{
    char buf[16], buf1[16], *p;
    int a, i, len;
    while (scanf("%d\n", &a) == 1) {
        len = sprintf(buf, "%d", a);
        for (i=len-1, p = buf1; i>=0; i--)
            p+=sprintf(p, "%c", buf[i]);
        *p='\0'; /*null-terminator*/
        printf("%d\n", atoi(buf1));
    }
    return 0;
}
