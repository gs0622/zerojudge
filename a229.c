#include <stdio.h>

int n;

void dfs(int r, int l, char *s)
{
    if (l == n) puts(s-2*n);
    if (r < n) *s = '(', dfs(r+1, l, s+1); /*not visited*/
    if (r > l) *s = ')', dfs(r, l+1, s+1); /*not visited*/
}

int main(void)
{
    char s[64];
#if 0
    freopen("a229.in", "r", stdin);
#endif
    while(scanf("%d", &n)==1 && n<=13) s[2*n] = '\0', dfs(0, 0, s), puts("");
    return 0;
}
