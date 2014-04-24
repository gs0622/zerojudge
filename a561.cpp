#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
    int n, i, j;
    std::priority_queue<int, std::vector<int>,
        std::greater<int> > q; // min-heap
    while (scanf("%d\n", &n)==1 && n && n<10000000) {
        for (i=0;i<n;i++) {
            scanf("%d", &j);
            if (0==j%10) q.push(j);
        }
        while (!q.empty()) {
            printf("%d ", q.top());
            q.pop();
        }
    }
    return 0;
}
