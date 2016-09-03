//给你一棵树，每条边都有权值，给你两个人去遍历这棵树，问将这棵树遍历完的最小代价是多少，
//给定两个人的起点，两个人不一定要回到起点
//权值*2-直径
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N =1000005;
int dp[100005][2], n, s, head[100005], d[10005], e, ans, sum;
bool f[100005];

struct Edge
{
	int v, next, w;
}g[N];

void init()
{
	sum = ans = e = 0;
	memset(head, -1, sizeof(head));
	memset(f, false, sizeof(f));
	memset(d, 0, sizeof(d));
}

void add(int u, int v, int w)
{
	g[e].v = v;
	g[e].w = w;
	g[e].next = head[u];
	head[u] = e++;
}

void dfs(int u)
{
	f[u] = true;
	int i;
	for (i = head[u]; i != -1; i = g[i].next)
	{
		int t = g[i].v;
		if (f[t] == false)
		{
			dfs(t);
			if (dp[u][0] < dp[t][0] + g[i].w)
			{
				dp[u][1] = dp[u][0];
				dp[u][0] = dp[t][0] + g[i].w;
			}
			else if (dp[u][1] < dp[t][0] + g[i].w)
				dp[u][1] = dp[t][0] + g[i].w;
		}
	}
	ans = max(ans, dp[u][0] + dp[u][1]);
}

int main()
{
	int i, j, k, u, v, w;
	while (scanf("%d%d", &n, &s) != EOF)
	{
		init();
		for (i = 1; i < n; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
			d[u]++, d[v]++;
			sum += 2*w;
		}
		for (i = 1; i <= n; i++)
		{
			dp[i][0] = dp[i][1] = -1;
			if (d[i] == 1)
				dp[i][0] = 0;
		}
		dfs(s);
		printf("%d\n", sum-ans);
	}
	return 0;
}