//ÁÚ½Ó¾ØÕódijstra POJ1502 MPI Maelstrom
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define N 110
using namespace std;

const int INF = 0x6fffffff;

int n, p[N][N], dis[N];
char s[100];
bool vis[N];

void dijstra(int v)
{
	memset(vis, false, sizeof(vis));
	int mmin, i, j, id;
	for (i = 1; i <= n; i++)
	  dis[i] = p[v][i];
	vis[v] = true;
	for (i = 1; i < n; i++)
	{
		mmin = INF;
		for (j = 1; j <= n; j++)
		{
			if (!vis[j] && dis[j] < mmin)
			{
				id = j;
				mmin = dis[j];
			}
		}
		vis[id] = true;
		for (j = 1; j <= n; j++)
		{
			if (!vis[j] && dis[j] > dis[id] + p[id][j])
			  dis[j] = dis[id] + p[id][j];
		}
	}
}

int main()
{
	int i, j, ans;
	while (scanf("%d", &n) != EOF)
	{
		for (i=1; i<=n; i++)
		for (j=1; j<=i; j++)
		  p[i][j] = p[j][i] = INF;
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j <i; j++)
			{
				scanf("%s",s);
				if (s[0] != 'x')
					p[j][i] = p[i][j] = atoi(s);
			}
		}

		dijstra(1);
		for (i = 2, ans = -1; i <= n; i++)
		  if (dis[i] > ans)
			ans = dis[i];
		printf("%d\n", ans);
		
	}
	return 0;
}

