//简单模拟
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100000+10;
const int M = 100000+50;

int t, n, m, q, c[N];
vector<int> v[N];

int main()
{
	int order, ans, a, b;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			c[i] = 0;
			v[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d", &order);
			if (order)
			{
				scanf("%d", &a);
				ans = 0;
				for (int i = 0; i < v[a].size(); i++)
					ans += c[v[a][i]];
				printf("%d\n", ans);
			}
			else
			{
				scanf("%d%d", &a, &b);
				c[a] += b;
			}
		}
	}
	return 0;
}