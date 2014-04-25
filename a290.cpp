#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 801
int G[MAX][MAX];
int visit[MAX];
int V, E;
queue<int> q;

int bfs(int s, int u) {
     int i, j, node;
     memset(visit, 0, sizeof(visit));
     q.push(s);
     while(!q.empty())
     {
          node = q.front();
          q.pop();
          if (visit[node]) continue;
          visit[node] = 1;
          cout << node << "->";
          for(i=0; i<MAX; i++)
               if(G[node][i]) q.push(i);
     }
     cout << endl;
}

int main(void)
{
    int N, M, a, b, A, B, i;
    char *ans[2] = {"No!!!", "Yes!!!"};
    //freopen("a290.in", "r", stdin);
    while (scanf("%d %d", &N, &M)==2) {
        bzero((void *)G, sizeof(G));
        for (i=0;i<M;i++) {
            if (scanf("%d %d", &a, &b)==2) G[a][b]=1;
        }
        scanf("%d %d", &A, &B);
        printf("%d-%d\n", A, B);
        //puts(ans[(m[A][B]==1)]);
        bfs(A, B);
    }
    return 0;
}
