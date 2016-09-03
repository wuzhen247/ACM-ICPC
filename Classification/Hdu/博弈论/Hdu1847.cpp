//²©ÞÄ sg
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int sg[1050];

int getsg(int x)
{
    if (sg[x] != -1)
      return sg[x];
    bool vis[500];
    memset(vis, false, sizeof(vis));
    int tm = 1;
    while(x-tm>=0)
    {
        vis[getsg(x-tm)] = true;
        tm <<= 1;
    }
    for (int i = 0;;i++)
      if (!vis[i])
        return sg[x] = i;
}


int main()
{
    int n, ans;
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    while (scanf("%d", &n) != EOF)
    {
        ans = getsg(n);
        if (ans)
          printf("Kiki\n");
        else
          printf("Cici\n");
    }
    return 0;
}

