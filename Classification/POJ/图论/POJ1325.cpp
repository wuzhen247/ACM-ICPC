//POJ1325 Machine Schedule 最小点覆盖 = 最大匹配 匈牙利算法
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1050
using namespace std;

int n, m, k, g[110][110], u, v, ans;
int link[110];
bool vis[110];

bool dfs(int u)
{
	int j;
	for (j = 1; j <= m; j++)
	{
		if (g[u][j] && !vis[j])
		{
			vis[j] = true;
			if (link[j] == -1 || dfs(link[j]))
			{
				link[j] = u;
				return true;
			}
		}
	}
	return false;
}
			

void hungary()
{
	memset(link, -1, sizeof(link));
	int i;
	for (i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
		  ans++;
	}
}

int main()
{
	int tm;
	while (scanf("%d", &n), n)
	{
		ans = 0;
		scanf("%d%d", &m, &k);
		memset(g, 0, sizeof(g));
		while(k--)
		{
			scanf("%d%d%d", &tm, &u, &v);
			if (u * v)
				g[u+1][v+1] = 1;
		}
		hungary();
		printf("%d\n", ans);
	}
	return 0;
}
