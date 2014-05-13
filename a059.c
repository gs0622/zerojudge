#include <stdio.h>
#include <math.h>

#define START(i,a)  (i=(int)ceil(sqrt((double)a)))
#define END(i,b)    (i<=(int)floor(sqrt((double)b)))

int main(void)
{
    int i, t, tt, a, b, s;
#if 0
    freopen("a059.in", "r", stdin);
#endif
    while (scanf("%d\n", &t)==1 && t) {
        tt = t;
        while (t--) {
            scanf("%d\n%d", &a, &b); 
            for (START(i,a), s=0; END(i,b);i++)  s+=i*i;
            printf("Case %d: %d\n", tt-t, s);
        }
    }
    return 0;
}
