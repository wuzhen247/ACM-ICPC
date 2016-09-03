/*acdream 1112 博弈
  对n可进行取约数和分解为a*b两种操作（不含1*n）；
  可转换为对石子数n进行取和分两种操作*/  
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 5000500
using namespace std;

int n;
bool vis[N];
int p[N/10], mi[N], np;
int dp[N], sg[N];

void getprime()
{
	memset(vis, true, sizeof(vis));
	vis[1] = vis[0] = false;
	for (int i = 1; i < N;i++)	mi[i] = i;
	for (int i = 2; i < N; ++i)
	{
		if (vis[i])
			p[++np] = i;
		for (int j = 1; j<=np && i*p[j]<N; j++)
		{
			vis[i*p[j]] = false;
			mi[i*p[j]] = p[j];	//n的最小素数
			if (i%p[j] == 0)
				break;
		}
	}
}

void Dp()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 2; i < N; ++i)
		dp[i] =dp[i/mi[i]] + 1;	//素因子个数
}

int getsg(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool mex[1000];
	memset(mex, false, sizeof(mex));
	for (int i = 0; i < x; i++)
		mex[getsg(i)] = true;
	for (int i = 1; i <= x-i; i++)
		mex[getsg(i)^getsg(x-i)] = true;
	for (int i = 0;; i++)
		if (!mex[i])
			return sg[x] = i;
}

int main()
{
	int ans, x;
	getprime();
	Dp();
	memset(sg, -1, sizeof(sg));

	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			ans ^= getsg(dp[x]);
		}
		if (ans)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}