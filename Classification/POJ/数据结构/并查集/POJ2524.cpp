/*简单并查集*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
const int N = 50000+5;
set<int> s;
int n, m, f[N];

int find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}

void union_set(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
        return;
    f[fa] = fb;
}

int main()
{
    int cas = 0;
    while (scanf("%d%d", &n, &m) && (n||m))
    {
        s.clear();
        for (int i = 1; i <= n; i++)
            f[i] = i;
        int a, b;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a, &b);
            union_set(a, b);
        }
        for (int i = 1; i <= n; i++)
            s.insert(find(i));
        printf("Case %d: %d\n", ++cas, s.size());
    }
    return 0;
}
