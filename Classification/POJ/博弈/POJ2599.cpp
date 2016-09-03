//博弈 P/N态分析
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
int n, k, head[N], e, sg[N], ans;
bool f[N];

struct Edge
{
	int v, next;
}g[4*N];

void init()
{
	e = 0;
	ans = N;
	memset(head, -1, sizeof(head));
	memset(sg, 0, sizeof(sg));
	memset(f, false, sizeof(f));
}

void add(int u, int v)
{
	g[e].v = v;
	g[e].next = head[u];
	head[u] = e++;
}

int getsg(int u)
{
	f[u] = true;
	int i;
	for (i = head[u]; i != -1; i = g[i].next)
	{
		int w = g[i].v;
		if (!f[w] && !getsg(w))
		{
			if (u != k)	
				return sg[u] = 1;
			if (w < ans)
				ans = w;
			sg[u] = 1;
		}
	}
	return sg[u];
}

int main()
{
	int i, u, v;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		init();
		for (i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		f[k] = true;
		if (getsg(k))
			printf("First player wins flying to airport %d\n", ans);
		else
			printf("First player loses\n");
	}
	return 0;
}