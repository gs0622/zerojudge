#include <stdio.h>

const int a2d[26] = {
    10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21,
    22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33
};

int main(void)
{
    char str[10];
    int i, s, a, b;
#if 0
    freopen("a054.in", "r", stdin);
#endif
    while (scanf("%s\n", str)!=EOF) {
        for (i=0, s=0; i<8; i++) s += (str[i]-'0')*(8-i);
        for (i=0;i<26;i++) {
            a=a2d[i], b=s, b+=(a/10)+(a%10)*9;
            if ((10-b%10)%10==str[8]-'0') printf("%c", i+'A');
        }
        printf("\n");
    }
    return 0;
}
