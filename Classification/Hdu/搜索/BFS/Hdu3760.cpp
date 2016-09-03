/*Hdu3760，从终点宽搜到1，得到最短路，再从1宽搜到n，得到最小字典序*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100000+5;

struct Edge
{
    int v, c;
    Edge(){}
    Edge(int tv, int tc):v(tv), c(tc){}
};
vector<Edge> g[N];
int t, n, m, dis[N], q[N], front, rear, cur, ter, ans[N];
bool vis[N];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            g[i].clear();
        memset(dis, -1, sizeof(dis));
        int a, b, c;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a == b) continue;
            g[a].push_back(Edge(b, c));
            g[b].push_back(Edge(a, c));
        }
        front = rear = 0;
        q[rear++] = n;
        dis[n] = 0;
        int tm;
        while (front < rear)
        {
            cur = q[front++];
            for (int i = 0; i < g[cur].size(); i++)
            {
                tm = g[cur][i].v;
                if (dis[tm] == -1)
                {
                    dis[tm] = dis[cur] + 1;
                    q[rear++] = tm;
                }
            }
        }
        printf("%d\n", dis[1]);
        
        memset(vis, false, sizeof(vis));
        front = rear = 0;
        q[rear++] = 1;
        ter = rear;
        int id, ma;
        bool isend = false;
        int count = dis[1];
        vis[1] = true;
        int num = 0;
        while (front < rear)
        {
            count--;
            ma = 1000000000+9;
            for (int k = front; k < ter; k++)
            {
                cur = q[k];
                for (int i = 0; i < g[cur].size(); i++)
                {
                    tm = g[cur][i].v;
                    if (!vis[tm] && dis[tm] == count)
                    {
                        if (g[cur][i].c < ma)
                            ma = g[cur][i].c;
                    }
                }
            }
            ans[++num] = ma;
            for (int k = front; k < ter; k++)
            {
                cur = q[k];
                for (int i = 0; i < g[cur].size(); i++)
                {
                    tm = g[cur][i].v;
                    if (!vis[tm] && dis[tm] == count)
                    {
                        if (g[cur][i].c == ma)
                        {
                            vis[tm] = true;
                            q[rear++] = tm;
                            if (tm == n)
                            {
                                isend = true;
                                break;
                            }
                        }
                    }
                }
                if (isend)  break;
            }
            if (isend)  break;
            front = ter;
            ter = rear;
        }
        for (int i = 1; i <= num; i++)
        {
            printf("%d", ans[i]);
            printf(i == num?"\n":" ");
        }

    }
    return 0;
}
