#include <stdio.h>

static long long dp[30001] = {1};

int main(void)
{
    int i, j, k, cent[5] = {1, 5 , 10, 25, 50};
    /*long long max = 0;*/
    for (i = 0; i < 5; i++) { /*select cent[j]*/
        for (j = cent[i]; j <= 30000; j++) { /*start from cent[i]*/
            dp[j] += dp[j - cent[i]];
            /*max = max > dp[j]? max: dp[j];*/
        }
    }
    /*printf("max = %lld\n", max);*/
    while (scanf("%d", &k) == 1 && k <= 30000) {
        if (dp[k] == 1)
            printf("There is only 1 way to produce %d cents change.\n", k);
        else
            printf("There are %lld ways to produce %d cents change.\n", dp[k], k);
    }
    return 0;
}

