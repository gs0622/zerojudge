#include <stdio.h>

static long long dp[30005] = {1};

int main(void)
{
    int i, j, k, cent[5] = {1, 5 , 10, 25, 50};
    for (i = 0; i < 5; i++) {
        for (j = cent[i]; j <= 30000; j++)
            dp[j] += dp[j - cent[i]];
    }
    while (scanf("%d", &k) == 1) {
        if (dp[k] == 1) printf("There is only 1 way to produce %d cents change.\n", k);
        else printf("There are %lld ways to produce %d cents change.\n", dp[k], k);
    }
    return 0;
}

