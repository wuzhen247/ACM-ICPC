//快速幂,注意MOD结果为正，注意结果为负时的处理
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = 10000000007LL;

ll multi(ll a,ll b)
{
    ll ans = 0, tm = a % MOD;
    while (b)
    {
        if (b&1)
        {
            ans += tm;
            if (ans >= MOD)
              ans -= MOD;
        }
        tm += tm;
        if ( tm>= MOD)
          tm -= MOD;
        b >>= 1;
    }
    return ans;
}

ll pow(ll a, ll n)
{
    ll ans = 1, tm = a%MOD;
    while(n)
    {
        if (n & 1)
            ans = multi(ans,tm);
        tm = multi(tm,tm); 
        n >>= 1;
    }
    return ans;
}

int main()
{
    int t, n;
    ll k, ans, x;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%lld",&n,&k);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            if (x < 0)
            {
                if (k & 1)
                  ans -= pow((-x),k);
                else
                  ans += pow((-x),k);
            }
            else
              ans += pow(x,k);
        }
        printf("%lld\n",(ans % MOD + MOD) % MOD);
    }
    return 0;
}

