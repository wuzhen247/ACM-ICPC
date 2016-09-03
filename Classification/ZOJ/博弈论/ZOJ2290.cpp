//必败点是斐波那契数 递归求第一步的最小值
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int dp[100];
const int inf = 100000000+2;

int dfs(int n)
{
	int k = 0;
	while (dp[k] < n)
		k++;
	if (dp[k] == n)
		return dp[k];
	return dfs(n-dp[k-1]);
}

int main()
{
	int i, n;
	dp[0] = dp[1] = 1;
	for (i = 2;; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
		if (dp[i] > inf)
			break;
	}
	while (scanf("%d", &n) != EOF)
	{
		i = 0;
		while (dp[i] < n)
			i++;
		if (dp[i] == n)
			printf("lose\n");
		else
			printf("%d\n", dfs(n-dp[i-1]));
	}	
	return 0;
}