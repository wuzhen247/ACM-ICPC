//POJ2425 A Chess Game ÒÆ¶¯Æå×Ó£¬Ê÷ÉÏ²©ÞÄ
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1010
using namespace std;

int n, m, g[N][N];
int sg[N*100];

void dfs(int v)
{
	bool vis[N];
	int i;
	memset(vis,false,sizeof(vis));
	for (i = 1; i <=g[v][0]; i++)
	{
		if (sg[g[v][i]] == -1)
			dfs(g[v][i]);
		vis[sg[g[v][i]]] = true;
	}
	for (i = 0; ; i++)
	  if (vis[i] == 0)
	  {
		  sg[v] = i;
		  break;
	  }
}


int main()
{
	int i, j, tm, ans;
	while(scanf("%d", &n) != EOF)
	{
		memset(g, -1 ,sizeof(g));
		memset(sg, -1, sizeof(sg));
		for(i = 0; i < n; i++)
		{
			scanf("%d", &m);
			g[i][0] = m;
			for (j = 1; j <= m; j++)
				scanf("%d", &g[i][j]);
		}
		for (i = 0; i < n; i++)
		  if (sg[i] == -1)
			dfs(i);
		while(scanf("%d", &m),m)
		{
			ans = 0;
			for (i = 0; i < m; i++)
			{
				scanf("%d", &tm);
				ans ^= sg[tm];
			}
			if (ans)
			  printf("WIN\n");
			else
			  printf("LOSE\n");
		}
	}
	return 0;
}
