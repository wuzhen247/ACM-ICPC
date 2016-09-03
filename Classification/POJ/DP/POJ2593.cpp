//连续两项子序列和最大
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100050;
int f[N], r[N], a[N];

int main()
{
	int n, i, j, sum, Max, ans;
	while (scanf("%d", &n), n)
	{
		Max = -0x3f3f3f3f;
		sum = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			if (sum > Max)
				Max = sum;
			f[i] = Max;
			if (sum < 0)
				sum = 0;
		}
		Max = -0x3f3f3f3f;
		sum = 0;
		for (i = n; i >= 1; i--)
		{
			sum += a[i];
			if (sum > Max)
				Max = sum;
			r[i] = Max;
			if (sum < 0)
				sum = 0;
		}
		ans = -0x3f3f3f3f;
		for (i = 1; i < n; i++)
			if (f[i] + r[i+1] > ans)
				ans = f[i]+r[i+1];
		printf("%d\n", ans);
	}
	return 0;
}