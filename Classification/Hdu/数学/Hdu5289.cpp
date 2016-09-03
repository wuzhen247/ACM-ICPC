/*区间最值问题，用ST统计，nlogn预处理，O(1)查询*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;
const int N = 100000+5;
int t, n, m, mi[N][20], ma[N][20], a[N];

void init()
{
    for (int i = 1; i <= n; i++)
        mi[i][0] = ma[i][0] = a[i];
    for (int i = 1; (1<<i)<= n; i++)
    {
        for (int j = 1; j+(1<<i)-1<= n; j++)
        {
            mi[j][i] = min(mi[j][i-1], mi[j+(1<<(i-1))][i-1]);
            ma[j][i] = max(ma[j][i-1], ma[j+(1<<(i-1))][i-1]);
        }
    }
}

int getmi(int l, int r)
{ 
    int k = (log(r-l+1.0)/log(2.0));
    return min(mi[l][k], mi[r-(1<<k)+1][k]);
}

int getma(int l, int r)
{ 
    int k = (log(r-l+1.0)/log(2.0));
    return max(ma[l][k], ma[r-(1<<k)+1][k]);
}


int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        init();
        ll ans = 0;
        int l = 1;
        for (int i = 1; i <= n; i++)
        {
            int r = i, mid, mam, mim;
            while (l <= r)
            {
                mid = (l+r)>>1;
                mim = getmi(mid, i);
                mam = getma(mid, i);
                if (mam - mim >= m)
                    l = mid+1;
                else
                    r = mid-1;
            }
            ans += i-l+1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
