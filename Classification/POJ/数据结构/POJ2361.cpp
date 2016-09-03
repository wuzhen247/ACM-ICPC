#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 10010;

struct Edge
{
	int v, next, w;
}g[N];

int dp[N][2], n, head[N], e, ans, d[N];
bool vis[N];

void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(d, 0, sizeof(d));
}

void add(int u, int v, int w)
{
//	d[u]++;
//	d[v]++;
//	g[e].v = v;
//	g[e].w = w;
//	g[e].next = head[u];
//	head[u] = e++;
}

void readgra()
{
	init();
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		add(a, b, c);
		add(b, a, c);
	}
	n = e;
}

void dfs(int cur)
{
	vis[cur] = false;
	for (int i = head[cur]; i != -1; i = g[i].next)
	{
		int t = g[i].v;
		if (!vis[t])
		{
			dfs(t);
			if (dp[t][0] + g[i].w > dp[cur][0])
			{
				dp[cur][1] = dp[cur][0];
				dp[cur][0] = dp[t][0] + g[i].w;
			}
			else if (dp[t][0] + g[i].w > dp[cur][1])
				dp[cur][1] = dp[t][0] + g[i].w; 
		}
	}
	ans = max(ans, dp[cur][0]+dp[cur][1]);
}

int main()
{
	readgra();
	ans = -1;
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = dp[i][1] = -1;
		if (d[i] == 0)
			dp[i][0] = 0;
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}