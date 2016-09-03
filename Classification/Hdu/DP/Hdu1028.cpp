//整数划分-dp
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 125;
int dp[N][N];

int main()
{
	int i, j, k, n;
	dp[0][0] = dp[1][1] = 1;
	for (i = 1; i < N; i++)
	{
		dp[i][1] = 1;
		for (j = 2; j <= i; j++)
		{
			k = (i - j) > j? j : (i-j);
			dp[i][j] = dp[i-j][k] + dp[i][j-1];
		}
	}
	while (scanf("%d", &n) != EOF)
		printf("%d\n", dp[n][n]);
	return 0;
}