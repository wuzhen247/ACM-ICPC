//POJ1611 简单并查集，查0号的子孙个数
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 30000+5;
int n, m, k, f[N];

int find(int x)
{
    if (x == f[x])
        return x;
    int tm = f[x];
    tm = find(tm);
    return f[x] = tm;
}

void union_set(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    if (fx == 0)
        f[fy] = 0;
    else if (fy == 0)
        f[fx] = 0;
    else
        f[fy] = fx;
}

int main()
{
    while (scanf("%d%d", &n, &m) && (n || m))
    {
        int tm, fx;
        for (int i = 0; i <= n; i++)
            f[i] = i;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &k);
            scanf("%d", &tm);
            fx = find(tm);
            for (int j = 1; j < k; j++)
            {
                scanf("%d", &tm);
                if (tm == 0)
                    union_set(tm, fx);
                else
                    union_set(fx, tm);
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            //cout<<i<<":"<<find(i)<<endl;
            if (find(i) == 0)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
