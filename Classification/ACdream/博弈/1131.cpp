//acdream Apple 博弈 P/N分析 注意搜索方向和剪枝
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[100001][40];
int N, M, A;

bool OK(int n, int m)
{
	int ans = 1;
	while (m--)
	{
		ans *= n;
		if (ans >= A)
			return true;
	}
	return false;
}

int power(int a, int n)
{
	int ans = 1, tm = a;
	while(n)
	{
		if (n & 1)
			ans *= tm;
		tm *= tm;
		n >>= 1;
	}
	return ans;
}

int getsg(int n, int m)
{
    if (n == 1)
    {
    	if (OK(n+1,m))
    		return 2;
    	else
    	{
    		int a = -1, b = -1;
    		if (!OK(n,m+1))
    		{
    			b = getsg(n,m+1);
    			if (b == 0)
    				return 1;
    		}
    		if (!OK(n+1,m))
    		{
    			a = getsg(n+1,m);
    			if (a == 0)
    				return 1;
    		}
    		if (a == 2 || b == 2)
    			return 2;
    		else
    			return 0;
    	}
    }
	else
	{
		if (dp[n][m] != -1)
			return dp[n][m];
		int a = -1, b = -1;
		if (power(n,m+1)<A)
		{
			b = getsg(n,m+1);
			if (b == 0)
				return dp[n][m] = 1;
		}
		if (power(n+1,m)<A)
		{
			a = getsg(n+1,m);
			if (a == 0)
				return dp[n][m] = 1;
		}
		return dp[n][m] = 0;
	}
}


int main()
{
	int ans;
	while(scanf("%d%d%d", &N, &M, &A) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		if (N == 1 && OK(N+1,M))
			printf("draw\n");
		else if (OK(N,M))
			printf("lose\n");
		else
		{
			int ans = getsg(N,M);
			if (ans == 1)
				printf("win\n");
			else if (ans == 0)
				printf("lose\n");
			else
				printf("draw\n");
		}
	}
	return 0;
}