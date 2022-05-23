#include <queue>

using namespace std;
typedef long long ll;
struct Edge
{
    int z, val, nexty;
} edge[1000000];
int head[200000];
ll dis[200000];
bool vis[200000] = {0};
int cnt = 0;

inline void add(int a, int b, int c)
{
    cnt++;
    edge[cnt].z = b;
    edge[cnt].val = c;
    edge[cnt].nexty = head[a];
    head[a] = cnt;
}

struct node
{
    int dis;
    int pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};

priority_queue<node> q;
int main()
{

    dis[0] = 0;
    q.push((node){0, 0});
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = edge[i].nexty)
        {
            int y = edge[i].z;
            if (dis[y] > dis[x] + edge[i].val)
            {
                dis[y] = dis[x] + edge[i].val;
                if (!vis[y])
                {
                    q.push((node){dis[y], y});
                }
            }
        }
    }
}