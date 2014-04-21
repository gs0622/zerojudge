/*http://zerojudge.tw/ShowProblem?problemid=a0009*/
#include <stdio.h>
#include <string.h>

char *decode(char *buf, int k)
{
    int i;
    for (i=0; i<strlen(buf); i++) buf[i]-=k;
    return buf;
}

int main(void)
{
#if 1
    char buf[1024];
    const int k=7;
    while (scanf("%s\n", &buf) != EOF) {
        printf("%s\n", decode(buf, k));
    }
#else /*probe K*/
    char t1[] = "1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5";
    char t2[] = "*CDC is the trademark of the Control Data Corporation.";
    int i;
    for (i=0; i<strlen(t1); i++) printf("%d ", t2[i]-t1[i]);
#endif
    return 0;
}
