//01背包
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 3500;
const int M = 13000;

int n, m;
int a[N], b[N], dp[M];

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &a[i], &b[i]);
		for (int i = 1; i <= n; i++)
			for (int v = m; v >= a[i]; v--)
				dp[v] = max(dp[v], dp[v-a[i]] + b[i]);
		printf("%d\n", dp[m]);
	}
	return 0;
}