//拓扑排序
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

const int N = 30000+5;
const int M = 100000+5;

int n, m, e;
int head[N], d[N], ans[N], num;
priority_queue<int>q;

struct Edge
{
	int v, next;
}p[M];

void init()
{
	e = 0;
	num = 0;
	memset(head, -1, sizeof(head));
	memset(d, 0, sizeof(d));
	while (!q.empty())	q.pop();
}

void add(int u, int v)
{
	p[e].v = v;
	p[e].next = head[u];
	head[u] = e++;
}

void solve()
{
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q.push(i);
	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		ans[++num] = u;
		int k = head[u];
		while (k != -1)
		{
			d[p[k].v]--;
			if (d[p[k].v] == 0)
				q.push(p[k].v);
			k = p[k].next;
		}
	}
	for (int i = num; i > 1; i--)
		printf("%d ", ans[i]);
	printf("%d\n", ans[1]);
}

int main()
{
	int t, u, v;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			add(v,u);
			d[u]++;
		}
		solve();
	}
	return 0;
}