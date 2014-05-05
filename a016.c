#include <stdio.h>
#include <string.h>

typedef union {
    int m[9][9];
    int c[3][3][3][3];
} sudoku_t;

int main(void)
{
    int i, j, k, l, bitmap, yes;
    sudoku_t s;
#if 0
    freopen("a016.in", "r", stdin);
#endif
    while (scanf("%d", &s.m[0][0])!=EOF) {
        for (i=1;i<81;i++) scanf("%d", &s.m[i/9][i%9]);
        yes=1;
        for (i=0;i<3;i++) {
            for (j=0;j<3;j++) {
                bitmap=0;
                for (k=0;k<3;k++)
                    for (l=0;l<3;l++) bitmap |= 1<<s.c[i][k][j][l];
                if (bitmap!=0x3fe) {
                    yes=0;
                    break;
                }
            }
        }
        printf("%s\n", yes?"yes":"no");
    }
    return 0;
}
