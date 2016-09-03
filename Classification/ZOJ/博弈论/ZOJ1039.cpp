//2-20这19个数字的游戏。每取走一个数之后，这个数的倍数便不能再取，
//而且某两个不能取的数的和，也不能再取。
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int dp[1<<19], a[20];

int getstate(int state, int x)
{
	int tm = state;
	for (int i = x; i <= 20; i+=x)
		tm &= ~(1<<(i-2));
	for (int i = 2; i <= 20; i++)
	{
		if ((1<<(i-2)) & tm)
		{
			for (int j = x; i-2-j >= 0; j += x)
			{
				if (!((1<<(i-j-2)) & tm))
				{
					tm &= ~(1<<(i-2));
					break;
				}
			}
		}
	}
	return tm;
}

int getsg(int state)
{
	if (dp[state] != -1)
		return dp[state];
	for (int i = 2; i <= 20; i++)
	{
		if (state & (1<<(i-2)))
		{
			int tm = getstate(state, i);
			if (!getsg(tm))
				return dp[state] = 1;
		}
	}
	return dp[state] = 0;
}

int main()
{
	int t, n, cas;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		int state = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			state |= 1<<(a[i]-2);
		}
		printf("Scenario #%d:\n", cas);
		if (getsg(state) == 0)
			printf("There is no winning move.\n");
		else
		{
			printf("The winning moves are:");
			for (int i = 0; i < n; i++)
			{
				int tm = getstate(state, a[i]);
				if (!getsg(tm))
					printf(" %d", a[i]);
			}
			printf(".\n");
		}
		printf("\n");
	}
	return 0;
}