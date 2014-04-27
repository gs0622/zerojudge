#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 801
int adj[MAX][MAX];
int visit[MAX];
queue<int> q;

#if 1
void bfs(int s)
{
    int i, j;
    q.push(s);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        if (visit[i]) continue;
        visit[i] = 1;
        for (j=0; j<MAX; j++) {
            if(adj[i][j]) q.push(j);
        }
    }
}
#else
void bfs(int s)
{
    int i, j;
    q.push(s);
    visit[s] = 1;
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (j=0; j<MAX; j++) {
            if (adj[i][j] && !visit[j]) {
                q.push(j);
                visit[j] = 1;
            }
        }
    }
}
#endif

void dfs(int s)
{
    int j;
    visit[s] = 1;
    for (j=0; j<MAX; j++) {
        if (adj[s][j] && !visit[j]) {
            dfs(j);
        }
    }
}

int main(void)
{
    int N, M, a, b, A, B, i;
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
        //dfs(A);
        puts(ans[visit[B]]);
    }
    return 0;
}
