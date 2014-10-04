#include <stdio.h>
#include <stdlib.h>

static int day[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

static int leap(int yy)
{
    return (!(yy % 4) && (yy % 100)) || !(yy % 400);
}

static int days(int yy, int mm, int dd)
{
    int d = yy * 365 + day[mm-2] + dd;
    return d;
}

int main(void)
{
    int yy[2], mm[2], dd[2], d[3], i;
    while (scanf("%d %d %d", &yy[0], &mm[0], &dd[0]) != EOF) {
        scanf("%d %d %d", &yy[1], &mm[1], &dd[1]);
        d[0] = days(yy[0], mm[0], dd[0]);
        d[1] = days(yy[1], mm[1], dd[1]);
        d[3] = abs(d[0] - d[1]);
        if (yy[0] > yy[1]) {
            for (i = yy[1]; i < yy[0]; i++)
                if (leap(i)) d[3] += 1;
            if ((mm[0] > 2) && leap(yy[0])) d[3] += 1;
            if ((mm[1] > 2) && leap(yy[1])) d[3] -= 1;
        } else if (yy[1] > yy[0]) {
            for (i = yy[0]; i < yy[1]; i++)
                if (leap(i)) d[3] += 1;
            if ((mm[1] > 2) && leap(yy[1])) d[3] += 1;
            if ((mm[0] > 2) && leap(yy[0])) d[3] -= 1;
        } else {
            if (leap(yy[0])) {
                   if (mm[0] > 2 && mm[1] <= 2) d[3] += 1;
                   if (mm[1] > 2 && mm[0] <= 2) d[3] += 1;
            }
        }
        printf("%d\n", d[3]);
    }
    return 0;
}
