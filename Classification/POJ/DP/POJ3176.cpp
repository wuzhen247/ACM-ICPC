// Êý×ÖÈý½ÇÐÎ dp
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 400;
int ans[N][N], m[N][N], n;

int main()
{
    int i, j;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
          for (j = 1; j <= i; j++)
            scanf("%d", &m[i][j]);
        for (i = 1; i <= n; i++)
          ans[n][i] = m[n][i];
        for (i = n-1; i >= 1; i--)
        {
            for (j = 1; j <= i; j++)
              ans[i][j] = m[i][j] + max(ans[i+1][j], ans[i+1][j+1]);
        }
        printf("%d\n", ans[1][1]);
    }
    return 0;
}
