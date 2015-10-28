#include <stdio.h>
#include <string.h>
long hash(char *str) {
    long i, j;
    for (i=j=0; str[i]!='\0'; i++) j += str[i] + (31 * j);
    return j%500;
}
int main(void) {
    long i, j, k, hashcodes[500] = {};
    char str[10001];
    while (fgets(str, 10001, stdin) != NULL) {
        j = hash(str);
        //printf("%ld\t:%s\n", j, str);
        if (hashcodes[j] == 1) printf("YES\n");
        else hashcodes[j] = 1, printf("NO\n");
     } 
    return 0;
}

