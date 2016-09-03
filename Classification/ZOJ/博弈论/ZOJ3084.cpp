// ZOJ3084 S-Nim 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s[120], k, m, l;
int sg[10050];

int getsg(int x)
{
    if (sg[x] != -1)
      return sg[x];
    bool vis[1000];
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < k && x - s[i] >= 0; i++)
      vis[getsg(x-s[i])] = true;
    for (int i = 0; ; i++)
        if (vis[i] == false)
            return sg[x] = i;
}

int main()
{
    int ans, x;
    while (scanf("%d", &k), k)
    {
        memset(sg, -1, sizeof(sg));
        for (int i = 0; i < k; i++)
          scanf("%d", &s[i]);
        sort(s, s+k);
        scanf("%d", &m);
        while(m--)
        {
            ans = 0;
            scanf("%d", &l);
            while (l--)
            {
                scanf("%d", &x);
                ans ^= getsg(x);
            }
            if (ans)
              printf("W");
            else
              printf("L");
        }
        printf("\n");
    }
    return 0;
}
