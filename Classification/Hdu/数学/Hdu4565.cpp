//Hdu4565 So Easy! 共轭递推式
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll MOD, a, b, n;

struct Mat
{
	ll m[2][2];
};

Mat I = {1ll, 0ll, 0ll, 1ll};

Mat matmul(Mat a, Mat b)
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

Mat matpower(Mat a, int n)
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

int main()
{
	ll ans;
	while (scanf("%lld%lld%lld%lld", &a, &b, &n, &MOD) != EOF)
	{
		Mat base = {a%MOD*2, (b-((a%MOD)*(a%MOD))%MOD)%MOD, 1, 0};
		Mat tm = matpower(base, n-1);
		ans = tm.m[0][0]*2*a + tm.m[0][1]*2;
		ans = (ans%MOD + MOD)%MOD;
		printf("%lld\n", ans);
	}
}