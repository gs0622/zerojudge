/*http://zerojudge.tw/ShowProblem?problemid=a004*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    int y;
    while (scanf("%d\n", &y) == 1) {
        if (0==(y%4)) {
            if ((0==(y%100))&&(0!=(y%400))) {
                printf("\u5E73\u5E74\n");
            } else {
                printf("\u958F\u5E74\n");
            }
        } else {
            printf("\u5E73\u5E74\n");
        }
    }
    return 0;
}
