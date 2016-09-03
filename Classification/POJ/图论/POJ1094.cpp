//POJ Sorting It All Out 拓扑排序
//关系确定即可忽略后面的输入
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, cnt;
int map[30][30], d[30];
char q[30];

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
                for (k = 0; k < n; k ++)
                {
                    if (map[j][k] == 1)
                      dt[k]--;
                }
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
    while (scanf("%d%d", &n, &m), n||m)
    {
        getchar();
        memset(map, 0, sizeof(map));
        memset(d, 0, sizeof(d));

        bool f = false;
        for (i = 1; i <= m; i++)
        {
            if (f == false)
            {
                scanf("%c<%c", &u, &v);
                getchar();
                d[v-'A']++;
                map[u-'A'][v-'A'] = 1;
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
