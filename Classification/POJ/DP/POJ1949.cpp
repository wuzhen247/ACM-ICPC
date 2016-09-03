//dp POJ1949 Chores
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10005
using namespace std;

int n,dp[N];
int a[N][105];
int b[N];
int t[N];

int main()
{
	scanf("%d", &n);
	memset(dp,0,sizeof(dp));
	int i, j;
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &t[i], &b[i]);
		for(j = 1; j <= b[i]; j++)
			scanf("%d",&a[i][j]);
	}
	dp[1] = t[1];
	for(i = 2; i<= n; i++)
	{
		for(j = 1; j <= b[i]; j++)
			dp[i] = max(dp[i],dp[a[i][j]]);
		dp[i] += t[i];
	}
	int ans = dp[1];
	for(i = 2; i <= n;i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}