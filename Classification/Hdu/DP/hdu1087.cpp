//上升子序列最大和
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll INF = -1000000000000000;

int n;
ll a[1000+5], dp[1000+5], ans;
int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            dp[i] = a[i];
        }
        ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (a[j] < a[i])
                    dp[i] = max(dp[i], dp[j]+a[i]);
            }
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
