#include <stdio.h>
#include <queue>        // std::priority_queue

using namespace std;

int main(void)
{
    int n, i, j;
    while (scanf("%d\n", &n)==1 && n>=1 && n<=100000) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > q;
        for (i=0;i<n;i++) {
            scanf("%d", &j);
            q.push(j);
        }
        for (i=0;i<n;i++) {
            printf("%d ", q.top());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
