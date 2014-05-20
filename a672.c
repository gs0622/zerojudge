#include <stdio.h>
int k, x, y, z;
void foo(int xx, int yy, int k) {
    if (k==0) return ;
    if (xx-k<=x && xx+k>=x && yy-k<=y && yy+k>=y) z++;
    foo(xx+k, yy+k, k/2);
    foo(xx+k, yy-k, k/2);
    foo(xx-k, yy+k, k/2);
    foo(xx-k, yy-k, k/2);
}
int main(void)
{
    /*freopen("a672.in", "r", stdin);*/
    while (scanf("%d%d%d", &k, &x, &y)==3 && k+x+y) {
        z=0, foo(1024, 1024, k);
        printf("%3d\n", z);
    }
    return 0;
}
