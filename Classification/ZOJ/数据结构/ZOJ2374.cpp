//树上操作 Marbles on a tree
#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10005;

struct Edge
{
	int v, next;
}g[N];

int head[N], w[N], id, num, son, n, ans, e;
bool root[N];

void init()
{
	ans = e = 0;
	for (int i = 0; i <= n; i++)
	{
		root[i] = true;
		w[i] = 0;
		head[i] = -1;
	}
}

void add(int u, int v)
{
	g[e].v = v;
	g[e].next = head[u];
	head[u] = e++;
}

void dfs(int u)
{
	int del;
	for (int i = head[u]; i != -1; i = g[i].next)
	{
		dfs(g[i].v);
		del = w[g[i].v] - 1;
		w[u] += del;
		w[g[i].v] = 1;
		ans += abs(del);
	}
}

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		init();
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &id, &w[i], &num);
			while (num--)
			{
				scanf("%d", &son);
				root[son] = false;
				add(id, son);
			}
		}
		for (i = 1; i <= n; i++)
		{
			if (root[i])
			{
				dfs(i);
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}