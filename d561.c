#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[128];
    int len, dot, d, f;
#if 0
    freopen("d561.in", "r", stdin);
#endif  
    while (scanf("%s", s) == 1) {
        len = strlen(s);
        dot = (s[0]=='-')? 2: 1;
        d = (s[0]=='-')? (s[1]-'0'): s[0]-'0';
        f = (len>dot+1)? ((s[dot+1]-'0')*10):0;
        f += (len>dot+2)? (s[dot+2]-'0'):0;
        f += (len>dot+3)? ((s[dot+3]>'4')? 1:0):0;
        if (f==100) f=0, d+=1;
        printf("%s%d.%.2d\n", (s[0]=='-'&&(d|f))?"-":"", d, f);
    }
    return 0;
}
