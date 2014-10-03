#include <stdio.h>

static int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//static int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
/*
int leap(int yy)
{
    return !(yy % 4) && (yy % 100) || !(yy % 400);
}*/

int days(int yy, int mm, int dd)
{
    int d = yy * 365 + day[mm-2] + dd;
    //d += yy/4 + yy/400 - yy/100;
    return d;
}

int main(void)
{
    int yy, mm, dd;
    while (scanf("%d %d %d", &yy, &mm, &dd) != EOF) {
        printf("%d %d %d\n", yy, mm, dd);
        printf("%d\n", days(yy, mm, dd));
    }
}
