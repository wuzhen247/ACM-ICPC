/*POJ1456，在截止日期前卖n个物品获得的最大价值，贪心，优先队列优化*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 10000+5;
struct Node
{
    int v, d;
    bool operator < (Node const &o) const
    {
        return v > o.v;
    }
    
}a[N];

bool cmp(Node a, Node b)
{
    if (a.d == b.d)
        return a.v > b.v;
    return a.d < b.d;
}


int n, ans, t;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        priority_queue<Node> q;
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].v, &a[i].d);
        sort(a, a+n, cmp);
        t = ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].d > t)
            {
                t++;
                ans += a[i].v;
                q.push(a[i]);
            }
            else
            {
                if (!q.empty() && q.top().v < a[i].v)
                {
                    ans = ans - q.top().v + a[i].v;
                    q.pop();
                    q.push(a[i]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
