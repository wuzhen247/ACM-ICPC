#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N  = 21;
const int INF = 10000000;
int mins[N], minv[N];
int n, m, ans;

void init()
{
	mins[0] = minv[0] = 0;
	for (int i = 1; i < N; i++)
	{
		mins[i] = mins[i-1] + 2*i*i;
		minv[i] = minv[i-1] + i*i*i;
	}
}

void dfs(int deep, int sums, int sumv, int r, int h)
{
	if (deep == 0)
	{
		if (sumv == n && sums < ans)
			ans = sums;
		return;
	}
	if ((sums + mins[deep] > ans) || (sumv + minv[deep] > n)
		|| (2 * (n-sumv) / r + sums > ans))
		return;
	for (int i = r; i >= deep; i--)
	{
		if (deep == m)
			sums = i*i;
		int maxh = min(h, n-sumv-minv[deep-1]);
		for (int j = maxh; j >= deep; j--)
			dfs(deep-1, sums+2*i*j, sumv+i*i*j, i-1, j-1);
	}
}

int main()
{

	init();
	while (scanf("%d%d", &n, &m) != EOF)
	{
		ans = INF;
		dfs(m, 0, 0, sqrt(n), n);
		if (ans == INF)
			printf("0\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}