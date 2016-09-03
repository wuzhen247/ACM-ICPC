//Hdu4549 M斐波那契数列 F[n]%m=a^(Fib[n-1]%(m-1))*b^(Fib[n]%(m-1))%m 费马小定理  注意这里A^x=A^(x%Phi(C)+Phi(C)) (mod C)
//
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 3
#define MOD 1000000007
using namespace std;

struct Mt
{
	__int64 m[N][N];
};

__int64 a, b, n;

Mt s,d;

Mt mul(Mt a, Mt b)
{
	Mt ans;
	for (int i = 1; i <= 2; i++)
	  for (int j = 1; j <= 2; j++)
	  {
		  ans.m[i][j] = 0;
		  for (int k = 1; k <= 2; k++)
		  {
			  ans.m[i][j] += (a.m[i][k] * b.m[k][j]) % (MOD-1);
			  ans.m[i][j] %= (MOD-1);
		  }
	  }
	return ans;
}

__int64 pow(__int64 a, __int64 b)
{
	__int64 ans = 1, tm = a%MOD;
	while(b)
	{
		if (b & 1)
			ans = ans * tm % MOD;
		tm = tm * tm % MOD;
		b>>=1;
	}
	return ans;
}

Mt pow_mt(Mt t, __int64 n)
{
	Mt tm = t;
	Mt ans = s;
	while(n)
	{
		if (n&1)
			ans = mul(ans,tm);
		tm = mul(tm,tm);
		n>>=1;
	}
	return ans;
}


int main()
{
	while (scanf("%I64d%I64d%I64d", &a, &b, &n) !=EOF )
	{
		s.m[1][1] = 1, s.m[1][2] = 0;
		s.m[2][1] = 0, s.m[2][2] = 1;
		d.m[1][1] = 1, d.m[1][2] = 1;
		d.m[2][1] = 1, d.m[2][2] = 0;
		Mt ans = pow_mt(d, n);
		printf("%I64d\n",(pow(a,ans.m[2][2]) * pow(b,ans.m[2][1]))% MOD);
	}
	return 0;
}
