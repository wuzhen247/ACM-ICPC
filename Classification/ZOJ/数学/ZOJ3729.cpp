// ZOJ 3729 2013长沙D题 Arnold Fib循环节
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define N 4000005
using namespace std;
typedef unsigned long long ll;

struct Mat
{
	ll m[2][2];
};

Mat I = {1LL, 0LL, 0LL, 1LL};

bool vis[N];
ll p[N/10];
int np;

void getprime()
{
	memset(vis, true, sizeof(vis));
	vis[0] = vis[1] = false;
	np = 0;
	for (int i = 2; i < N; i++)
	{
		if (vis[i])
			p[++np] = i;
		for (int j = 1; p[j] * i < N && j <= np; j++)
		{
			vis[p[j] * i] = false;
			if (i % p[j] == 0)
				break;
		}
	}
}

Mat matmul(Mat a, Mat b, ll MOD)
{
	Mat c;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < 2; k++)
				c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
		}
	return c; 
}

Mat matpow(Mat a, ll n, ll MOD)
{
	Mat ans = I, tm = a;
	while (n)
	{
		if (n & 1)
			ans = matmul(ans, tm, MOD);
		tm = matmul(tm, tm, MOD);
		n >>= 1;
	}
	return ans;
}

ll pow(ll a, ll n, ll MOD)
{
	ll ans = 1, tm = a % MOD;
	while (n)
	{
		if (n & 1)
			ans = ans* tm % MOD;
		tm = tm * tm % MOD;
		n >>= 1;
	}
	return ans;
}

int Legendre(ll c, ll p)
{
	if (pow(c, (p-1)>>1, p) == 1)
		return 1;
	return 0;
}

bool isFib(Mat a, ll n, ll MOD)
{
	Mat ans = matpow(a, n, MOD);
	return (ans.m[0][0] == 1 && ans.m[1][1] == 1 &&
			ans.m[1][0] == 0 && ans.m[0][1] == 0);
}

ll fac[40000];
int num[40000], cnt;
ll factor[40000];


ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return a/gcd(a,b)*b;
}

int work(ll n)
{
	int tm = 0;
	ll m = sqrt(n + 0.5);
	for (ll i = 1; i <= m; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
				factor[++tm] = i;
			else
			{
				factor[++tm] = i;
				factor[++tm] = n/i;
			}
		}
	}
	return tm;
} 

ll find(ll n)
{
	ll cnt = 0;
	for (int i = 1; p[i] * p[i] <= n; i++)
	{
		if (n % p[i] == 0)
		{
			fac[++cnt] = p[i];
			num[cnt] = 0;
			while (n % p[i] == 0)
			{
				n /= p[i];
				num[cnt]++;
			}
		}
	}

	if (n > 1)
	{
		fac[++cnt] = n;
		num[cnt] = 1;
	}
	return cnt;
}

ll solve(ll n)
{
	Mat A = {1LL,1LL,1LL,0LL};
	ll cnt = find(n);
	ll ans = 1, ct;
	for (ll i = 1; i <= cnt; i++)
	{
		ll tm = 1;
		if (fac[i] == 2)
			tm = 3;
		else if (fac[i] == 3)
			tm = 8;
		else if (fac[i] == 5)
			tm = 20;
		else
		{
			if (Legendre(5,fac[i]) == 1)
				ct = work(fac[i]-1);
			else
				//ct = work((fac[i]-1)*(fac[i]+1));
				ct = work(2*(fac[i]+1));
			sort(factor+1, factor+1+ct);
			for (int j = 1; j <= ct; j++)
			{
				if (isFib(A, factor[j], fac[i]))
				{
					tm = factor[j];
					break;
				}
			}
			
		}
		tm = tm * pow(fac[i], num[i]-1);
		ans = lcm(ans, tm);
	}
	return ans;
}

int main()
{
	ll n;
	getprime();
	while (cin>>n)
		cout<<solve(n)/2<<endl;
	return 0;
}