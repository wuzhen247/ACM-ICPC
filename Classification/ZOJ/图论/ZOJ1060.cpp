//ZOJ1060 Sorting It All Out 拓扑排序
//关系确定即可忽略后面的输入
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int v, next;
}g[90000];

int head[30], e, d[30], cnt, n, m;
char q[30];

void init()
{
    memset(head, -1, sizeof(head));
    memset(d, 0, sizeof(d));
    e = 0;
}

void add(int u, int v)
{
    g[e].v = v;
    g[e].next = head[u];
    head[u] = e++;
}


int sol()
{
    int dt[30], i, j, k;
    bool f = false;
    cnt = 0;
    for (i = 0; i < n; i++)
      dt[i] = d[i];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dt[j] == 0)
            {
                q[cnt++] = j+'A';
                dt[j]--;
                for (k = j+1; k < n; k++)
                {
                    if (dt[k] == 0)
                      f = true;
                }
                for (k = head[j]; k != -1; k = g[k].next)
                    dt[g[k].v]--;
                break;
            }
        }
    }
    q[cnt] = '\0';
    if (cnt < n)
      return -1;
    else if (f)
      return 0;
    else
      return 1;
}


int main()
{
    int i, ans;
    char u, v;
    bool f;
    while (scanf("%d%d", &n, &m), n||m)
    {
        f = false;
        getchar();
        init();
        for (i = 1; i <= m; i++)
        {
            if (f == false)
            {
                scanf("%c<%c", &u, &v);
                getchar();
                d[v-'A']++;
                add(u-'A',v-'A');
                ans = sol();
                if (ans == -1)
                {
                    printf("Inconsistency found after %d relations.\n", i);
                    f = true;
                    continue;
                }
                else if (ans == 1)
                {
                    printf("Sorted sequence determined after %d relations: ",i);
                    printf("%s.\n", q);
                    f = true;
                    continue;
                }
            }
            else
            {
                scanf("%c<%c", &u, &v);
                getchar();
            }
        }
        if (f == false)
          printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
