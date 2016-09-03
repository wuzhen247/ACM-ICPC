//POJ3761 Bubble Sort 求逆序数最大为k的序列个数
#include <iostream>
#include <cstdio>
#include <cstring>
#define N  1000050 
using namespace std;
typedef long long ll;

const int MOD = 20100713;
ll a[N];

ll pow(ll a, ll n)
{
    ll ans = 1, tm = a % MOD;
    while (n)
    {
        if (n & 1)
          ans = (ans * tm) % MOD;
        tm = tm * tm % MOD;
        n >>= 1;
    }
    return ans;
}

void get()
{
    a[0] = 1;
    for (int i = 1; i < N; i++)
      a[i] = (a[i-1] * i)%MOD;
}



int main()
{
    int t, n, k;
    ll ans;
    get();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        ans = a[k] * (pow(k+1, n-k) - pow(k,n-k)) % MOD;
        printf("%lld\n", (ans % MOD + MOD)%MOD);
    }
    return 0;
}
