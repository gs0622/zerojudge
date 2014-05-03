#include <stdio.h>
#include <math.h>

#define MAX_PRIME   46349 
int prime[4793];

void primetable(void)
{
    int i, j, k, l=0;
    prime[l++]=2; /*1st prime*/
    for (i=3;i<=MAX_PRIME;i+=2) {
        int found=1;
        for (j=0,k=floor(sqrt(i));prime[j]<=k;j++) {
            if (i%prime[j]==0) {
                found=0 ;
                break ; 
            }
        }
        if (found) prime[l++]=i;
    }
}

int isprime(int n)
{
    int i, k;
    for (i=0,k=(int)floor(sqrt(n));prime[i]<=k;i++)
        if (n%prime[i]==0) return 0;
    return 1;
}
int main(void)
{
    int a;
    primetable(); /*build prime table*/
    while (scanf("%d\n", &a) == 1) {
        if (isprime(a))
            printf("質數\n");
        else
            printf("非質數\n");
    }
    return 0;
}
