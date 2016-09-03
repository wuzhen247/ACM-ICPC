/*ZOJ3641 并查集，节点附带信息，储存在父节点中，合并父节点信息，注意释放空间，否则超空间*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
const int N = 100000+5;
set<int> s[N];
map<string,int> m;

int t, n, f[N];
int find(int x)
{
    if (f[x] == x)
        return x;
    int tm = f[x];
    f[x] = find(tm);
    return f[x];
}

void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        f[fx] = fy;
        set<int>::iterator it;
        for (it = s[fx].begin(); it != s[fx].end(); it++)
            s[fy].insert(*it);
        s[fx].clear();
    }
}

int main()
{
    char order[20], na1[20], na2[20];
    int id, tm, fx, fy, x, y;
    while (scanf("%d", &t) != EOF)
    {
        id = 0;
        for (int i = 1; i < N; i++)
        {
            s[i].clear();
            f[i] = i;
        }
        m.clear();
        while (t--)
        {
            scanf("%s", order);
            if (strcmp(order, "arrive") == 0)
            {
                scanf("%s", na1);
                m[string(na1)] = ++id;
                scanf("%d", &n);
                fx = find(id);
                for (int i = 1; i <= n; i++)
                {
                    scanf("%d", &tm);
                    s[fx].insert(tm);
                }
            }
            else if (strcmp(order, "share") == 0)
            {
                scanf("%s %s", na1, na2);
                x = m[string(na1)];
                y = m[string(na2)];
                merge(x, y);
            }
            else
            {
                scanf("%s", na1);
                x = m[na1];
                fx = find(x);
                printf("%d\n", s[fx].size());
            }
        }
    }
    return 0;
}
