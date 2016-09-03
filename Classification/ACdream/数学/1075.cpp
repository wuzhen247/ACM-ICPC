//求Fib对1000000007的循环节
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int N = 2;

const ll MOD = 1000000007;

ll fac[2][505];
int cnt,ct;

ll pri[6] = {2, 3, 7, 109, 167, 500000003};
ll num[6] = {4, 2, 1, 2, 1, 1};

struct Mat
{
	ll m[2][2];
};

Mat I = {1, 0, 0, 1};

Mat matmul(Mat a, Mat b)
{
	Mat c;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
			}
		}
	return c;
}

Mat matpower(Mat a, ll n)
{
	Mat ans = I, tm = a;
	while (n)
	{
		if (n & 1)
			ans = matmul(ans, tm);
		tm = matmul(tm, tm);
		n >>= 1;
	}
	return ans;
}


ll power(ll a, ll n, ll p)
{
	ll ans = 1, tm = a % p;
	while (n)
	{
		if (n & 1)
			ans = ans * tm % p;
		tm = tm * tm % p;
		n >>= 1;
	}
	return ans;
}

int Legendre(ll c, ll p)
{
	if (power(c, (p-1)>>1, p) == 1)
		return 1;
	return -1;
}

void dfs(int dept, ll p)
{
	if (dept == cnt)
	{
		fac[1][ct++] = p;
		return;
	}
	for (int i = 0; i <= num[dept]; i++)
	{
		dfs(dept+1, p);
		p *= pri[dept];
	}
}

bool isFib(Mat a, ll n)
{
	Mat ans = matpower(a, n);
	return (ans.m[0][0] == 1 && ans.m[1][1] == 1 &&
			ans.m[0][1] == 0 && ans.m[1][0] == 0);
}

int main()
{
	ll a, b, c, d, t;
	Mat A;
	fac[0][0] = 1;
	fac[0][1] = 2;
	fac[0][2] = 500000003;
	fac[0][3] = 1000000006;
	while (cin>>a>>b>>c>>d)
	{
		t = a * a + 4 * b;
		A.m[0][0] = a;
		A.m[0][1] = b;
		A.m[1][0] = 1;
		A.m[1][1] = 0;
		if (Legendre(t, MOD) == 1)
		{
			for (int i = 0; i < 4; ++i)
			{
				if (isFib(A, fac[0][i]))
				{
					cout<<fac[0][i]<<endl;
					break;
				}
			}
		}
		else
		{
			cnt = 6;
			ct = 0;
			dfs(0,1);
			sort(fac[1], fac[1]+ct);
			for (int i = 0; i < ct; i++)
			{
				if (isFib(A, fac[1][i]))
				{
					cout<<fac[1][i]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}