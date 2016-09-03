//Hdu 最近叶子节点距离 树形dp，注意对INF过大可能超int
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 20000000;
const int N = 10005;
vector<int>e[N], w[N];
bool vis[N];
int n, a, b, c, d[N];
int ans, dp[N][2];

void dfs(int v)
{
	vis[v] = true;
	for (int i = 0; i < (int)e[v].size(); i++)
	{
		int t = e[v][i];
		if (!vis[t])
		{
			dfs(t);
			if (dp[t][0] + w[v][i] < dp[v][0])
			{
				dp[v][1] = dp[v][0];
				dp[v][0] = dp[t][0] + w[v][i];
			}
			else if (dp[t][0] + w[v][i] < dp[v][1])
				dp[v][1] = dp[t][0] + w[v][i];
		}
	}
	ans = min(ans, dp[v][0]+dp[v][1]);
}

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		for (i = 0; i <= n; i++)
		{
			e[i].clear();
			w[i].clear();
			d[i] = 0;
		}
		for (i = 1; i < n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			d[a]++, d[b]++;
			e[a].push_back(b), e[b].push_back(a);
			w[a].push_back(c), w[b].push_back(c);
		}
		for (i = 1; i <= n; i++)
		{
			dp[i][0] = dp[i][1] = INF;
			if (d[i] == 1)
				dp[i][0] = 0;
		}

		memset(vis, false, sizeof(vis));
		ans = INF;
		dfs(1);
		printf("%d\n", ans);

	}
	return 0;
}