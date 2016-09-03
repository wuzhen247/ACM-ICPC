//拓扑排序 POJ2367 Genealogical tree
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 10010;

struct Edge
{
	int v, next;
}g[N];

int head[105], e, n, d[105];

void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
	memset(d, 0, sizeof(d));
}

void add(int u, int v)
{
	g[e].v = v;
	g[e].next = head[u];
	head[u] = e++;
}

void sol()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (d[j] == 0)
			{
				printf("%d ", j);
				d[j]--;
				for (k = head[j]; k != -1; k = g[k].next)
					d[g[k].v]--;
			}
		}
	}
	printf("\n");
}

int main()
{
	int i, j, k, tm;
	while(scanf("%d", &n) != EOF)
	{
		init();
		for (i = 1; i <= n; i++)
		{
			while (scanf("%d", &tm), tm)
			{
				d[tm]++;
				add(i, tm);
			}
		}
		sol();
	}
	return 0;
}