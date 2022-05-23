#include <iostream>
#include <queue>

using namespace std;
#define int long long
#define js                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
struct Edge
{
    int to, val, nexty;
} edge[200005];
int head[100005], cnt;
void addedge(int u, int v, int val)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].val = val;
    edge[cnt].nexty = head[u];
    head[u] = cnt;
}
int n, m, s;
int dis[100005], vis[100005];
const int inf = 0x7fffffff;


void spfa() {
    queue<int> qu;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    qu.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = edge[i].nexty)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].val)
            {
                dis[v] = dis[u] + edge[i].val;
                if (vis[v] == 0)
                {
                    vis[v] = 1;
                    qu.push(v);
                }
            }
        }
    }
}
