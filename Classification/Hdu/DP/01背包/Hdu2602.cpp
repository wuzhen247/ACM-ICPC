//01±³°ü
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1000+5;
int dp[N], t, n, m, v[N], a[N];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 0; j--)
            {
                if (j-v[i] >= 0)
                    dp[j] = max(dp[j], dp[j-v[i]] + a[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
