#include <stdio.h>

int main(void)
{
    int row, col, i, j, m[100][100];
#if 0
    freopen("a015.in", "r", stdin);
#endif
    while (scanf("%d %d", &row, &col)==2 && row<100 && col<100) {
        for (i=0;i<row;i++)
            for (j=0;j<col; j++)
                scanf("%d", &m[i][j]);
        for (i=0;i<col;i++)
            for (j=0;j<row; j++)
                printf("%d%c", m[j][i], (j==row-1)?'\n':' ');
    }
    return 0;
}
