#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 801
int adj[MAX][MAX];
int visit[MAX];
int V, E;
queue<int> q;

void bfs(int s)
{
    int i, j, node;
    memset(visit, 0, sizeof(visit));
    q.push(s);
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if (visit[node]) continue;
        visit[node] = 1;
        for (i=0; i<MAX; i++)
            if(adj[node][i]) q.push(i);
    }
}

int main(void)
{
    int N, M, a, b, A, B, i;
    bool flag;
    char *ans[2] = {"No!!!", "Yes!!!"};
    //freopen("a290.in", "r", stdin);
    while (scanf("%d %d", &N, &M)==2) {
        bzero((void *)adj, sizeof(adj));
        bzero((void *)visit, sizeof(visit));
        for (i=0;i<M;i++) {
            if (scanf("%d %d", &a, &b)==2) adj[a][b]=1;
        }
        scanf("%d %d", &A, &B);
        bfs(A);
        puts(ans[visit[B]]);
    }
    return 0;
}
