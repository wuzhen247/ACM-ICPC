/*ͳ�Ƶ�ǰ���Դ𰸵Ĺ��ף���¼ÿ�������Ҷ˵�Լ��λ�ú����ͳ��*/
#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;
const int N = 100000+5;
const ll mod = 1000000007;
int a[N], n;
ll dpl[N], dpr[N], vis[N];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        memset(vis, 0, sizeof(vis));
        memset(dpl, 0, sizeof(dpl));
        for (int i = 1; i <= n; i++)
        {
            int tmp = a[i];
            for (int j = 1; j * j <= tmp; j++)
            {
                if (tmp % j == 0)
                {
                    dpl[i] = max(dpl[i], vis[j] + 1);
                    dpl[i] = max(dpl[i], vis[tmp/j] + 1);
                }
            }
            vis[tmp] = i;
        }
        for (int i = 1; i < N; i++)
        {
            vis[i] = n+1;
            dpr[i] = n+1;
        }
        for (int i = n; i >= 1; i--)
        {
            int tmp = a[i];
            for (int j = 1; j * j <= tmp; j++)
            {
                if (tmp % j == 0)
                {
                    dpr[i] = min(dpr[i], vis[j] - 1);
                    dpr[i] = min(dpr[i], vis[tmp/j] -1);
                }
            }
            vis[tmp] = i;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + ((i+1-dpl[i])*(dpr[i]+1-i) % mod))%mod;
        printf("%lld\n", ans);
    }
    return 0;
}
