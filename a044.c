/* Reference:
https://sites.google.com/site/zsgititit/home/c-cheng-shi-she-ji/a044-kong-jian-qie-ge
http://www.csghs.tp.edu.tw/Zhongshan/student/91science/M2.pdf
*/
#include <stdio.h>

int main(void)
{
    int n;
#if 0
    freopen("a044.in", "r", stdin);
#endif  
    while (scanf("%d", &n) == 1) {
        printf("%d\n", n*(n*n+5)/6+1);
    }
    return 0;
}
