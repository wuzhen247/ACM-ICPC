//LIS 最长不降子序列 nlogn
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 40040;

int a[N], dp[N], n;

int bisearch(int size, int k)
{
	int l = 1, r = size, mid;
	while (l <= r)
	{
		mid = (l+r)>>1;
		if (dp[mid] < k && k <= dp[mid+1])
			return mid+1;
		else if (k < dp[mid])
			r = mid-1;
		else
			l = mid+1;
	}
}

int LIS()
{
	int ans = 1, i, j;
	dp[1] = a[1];
	for (i = 2; i <= n; i++)
	{
		if (a[i] <= dp[1])
			j = 1;
		else if (a[i] > dp[ans])
			j = ++ans;
		else
			j = bisearch(ans, a[i]);
		dp[j] = a[i];
	}
	return ans;
}

int main()
{
	int i, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", LIS());
	}
}