#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000];
    int i, len, mid, yes;
#if 0
    freopen("a022.in", "r", stdin);
#endif
    while (scanf("%s", s)!=EOF) {
        len = strlen(s), mid = len/2, yes = 1;
        for (i=0;i<mid;i++) {
            if (s[i]!=s[len-i-1]) {
                yes = 0;
                break;
            }
        }
        printf("%s\n", yes?"yes":"no");
    }
    return 0;
}
