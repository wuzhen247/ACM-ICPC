//dp
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t, n, m;
int dp[22][1010], a[22][1010];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        int tm, k;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                tm = 0;
                if (i > 1 && j > 1)
                    tm = max(dp[i-1][j], dp[i][j-1]);
                else if (i > 1 && j == 1)
                    tm = dp[i-1][j];
                else if (i == 1 && j > 1)
                    tm = dp[i][j-1];
                k = 2;
                while (k <= j)
                {
                    if (j % k == 0)
                        tm = max(tm, dp[i][j/k]);
                    k++;
                }
                dp[i][j] = tm + a[i][j];
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
