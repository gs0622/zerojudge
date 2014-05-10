#include <stdio.h>

static int armstrong[20] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 153,
    370, 371, 407, 1634, 8208, 9474,
    54748, 92727, 93084, 548837
};

int main(void)
{
    int a, b, i, found;
#if 0
    freopen("a040.in", "r", stdin);
#endif  
    while (scanf("%d %d\n", &a, &b)==2 && a>0 && b>0) {
        for (i=0, found=0; i<20, armstrong[i]<b; i++) {
            if (armstrong[i]>=a) found = 1, printf("%d ", armstrong[i]);
        }
        if (!found) printf("none\n");
        printf("\n");
    }
    return 0;
}
