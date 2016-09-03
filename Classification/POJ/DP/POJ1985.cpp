//POJ 1985 树的直径 树形dp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = -1;
const int N = 100005;
vector<int>g[N], w[N];
bool vis[N];
int ans, n, m, dp[N][2], d[N];

void dfs(int cur)
{
	vis[cur] = true;
	for (int i = 0; i <(int)g[cur].size(); i++)
	{
		int t = g[cur][i];
		if (!vis[t])
		{
			dfs(t);
			if (dp[t][0] + w[cur][i] > dp[cur][0])
			{
				dp[cur][1] = dp[cur][0];
				dp[cur][0] = dp[t][0] + w[cur][i];
			}
			else if(dp[t][0] + w[cur][i] > dp[cur][1])
				dp[cur][1] = dp[t][0] + w[cur][i];
		}
	}
	ans = max(ans, dp[cur][0]+dp[cur][1]);
}

int main()
{
	char ch;
	int i, a, b, c;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0; i <= n; i++)
			g[i].clear(), w[i].clear(),d[i] = 0;
		for (i = 1; i < n; i++)
		{
			scanf("%d%d%d %c", &a, &b, &c, &ch);
			d[a]++, d[b]++;
			g[a].push_back(b), g[b].push_back(a);
			w[a].push_back(c), w[b].push_back(c);
		}
		for (i = 1; i <= n; i++)
		{
			dp[i][0] = dp[i][0] = INF;
			if (d[i] == 1)
				dp[i][0] = 0;
		}
		memset(vis, false, sizeof(vis));
		ans = -1;
		dfs(1);
		printf("%d\n", ans);
	}
}