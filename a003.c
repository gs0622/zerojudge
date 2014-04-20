/*http://zerojudge.tw/ShowProblem?problemid=a003*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    int m, d, s;
    while (scanf("%d %d\n", &m, &d) == 2) {
        s=(m*2+d)%3;
        if (0==s) printf("´¶³q\n");
        else if (1==s) printf("¦N\n");
        else printf("¤j¦N\n");
    }
    return 0;
}
