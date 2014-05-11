#include <stdio.h>
#include <string.h>

const int a2d[26] = {
    10/*A*/, 11, 12, 13, 14, 15, 16, 17,
    34/*I*/, 18, 19, 20, 21, 22, 35, 23,
    24/*Q*/, 25, 26, 27, 28, 29, 32, 30,
    31/*Y*/, 33
};

int idcheck(char *s)
{
    int i, sum = 0;
    if (!s || strlen(s)!=10) return 0;
    i = a2d[s[0]-'A'];
    sum += (i/10)+(i%10)*9;
    for (i=1; i<9; i++) sum += (s[i]-'0')*(9-i);
    sum += s[9]-'0';
    return (sum%10)?0/*fake*/:1/*real*/;
}

int main(void)
{
    char s[16];
#if 0
    freopen("a020.in", "r", stdin);
#endif
    while (scanf("%s\n", s)!=EOF) {
        printf("%s\n", idcheck(s)? "real":"fake");
    }
    return 0;
}
