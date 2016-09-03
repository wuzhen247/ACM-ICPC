//求中位数是m的子序列个数，用+-1处理，类似于天平dp问题
//大于关系小于关系及距离关系的转换
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 40000+5;
int n, m, a[N], b[N], id, c[N*2+5], ans;

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] == m)
			{
				b[i] = 0;
				id = i;
				continue;
			}
			if (a[i] > m)
				b[i] = 1;
			else
				b[i] = -1;
		}
		memset(c, 0, sizeof(c));
		b[id] = 40000;
		for (int i = id-1; i >= 1; i--)
		{
			b[i] += b[i+1];
			c[b[i]]++;
		}
		b[id] = 0;
		c[40000]++;
		ans += c[40000];
		for (int i = id+1; i <= n; i++)
		{
			b[i] += b[i-1];
			ans += c[40000-b[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}