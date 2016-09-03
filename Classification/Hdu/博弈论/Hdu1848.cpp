//²©ÞÄ ·ÇµÝ¹ésgÐ´·¨
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int fib[20];
int sg[1010];

void getsg()
{
    bool vis[1010];
    sg[0] = 0;
    sg[1] = 1;
    for (int i = 1; i < 1005; i++)
    {
        memset(vis, false, sizeof(vis));
        for (int j = 1; fib[j] <= i; j++)
          vis[sg[i-fib[j]]] = true;
        for (int j= 0;;j++)
          if (!vis[j])
          {
              sg[i] = j;
              break;
          }
    }
}

int main()
{
    int a, b, c;
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 19; i++)
      fib[i] = fib[i-1] + fib[i-2];
    getsg();
    while (cin>>a>>b>>c)
    {
        if (!(a||b||c))
          break;
        if (sg[a] ^ sg[b] ^ sg[c])
          printf("Fibo\n");
        else
          printf("Nacci\n");
    }
    return 0;
}
