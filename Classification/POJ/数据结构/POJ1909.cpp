//基本思路就是从叶子节点开始，有多出来的Marble就把多余的部分全部转移到父节点，
//不够的就从父节点转移相应的数目下去，如果父节点的Marble的数目不够，先记为负数，
//到了再上一层的时候再补上。
//树上操作
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 10005;

struct Edge
{
	int v, next;
}g[N];

int head[N], e, w[N], ans, n, u, num, son, id;
bool root[N];

void init()
{
	ans = e = 0;
	for (int i = 0; i <= n; i++)
	{
		head[i] = -1;
		w[i] = 0;
		root[i] = true;
	}
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

void add(int u, int v)
{
	g[e].v = v;
	g[e].next = head[u];
	head[u] = e++;
}

int main()
{
	int i, j, k;
	while (scanf("%d", &n), n)
	{
		init();
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &id, &w[i], &num);
			while (num--)
			{
				scanf("%d", &son);
				add(id, son);
				root[son] = false;
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