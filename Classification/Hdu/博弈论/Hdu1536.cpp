//SG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s[110], h[10050], k, m, l;
int sg[10050];

int getsg(int x)
{
    if (sg[x] != -1)
      return sg[x];
    bool vis[150];
    memset(vis, false, sizeof(vis));
    for (int i = 1; x-s[i]>=0 && i <= k; i++)
        vis[getsg(x-s[i])] = true;
    for (int i = 0; ;i++)
      if (vis[i] == false)
        return sg[x] = i;
}

int main()
{
    int ans;
    while (scanf("%d", &k), k)
    {
        for (int i = 1; i <= k; i++)
            scanf("%d", &s[i]);
        scanf("%d", &m);
        sort(s+1, s+k+1);
        memset(sg, -1, sizeof(sg));
        while(m--)
        {
            scanf("%d", &l);
            ans = 0;
            for (int i = 1; i <= l; i++)
            {
                scanf("%d", &h[i]);
                ans ^= getsg(h[i]);
            }
            if (ans)    printf("W");
            else    printf("L");
        }
        printf("\n");
    }
    return 0;
}
