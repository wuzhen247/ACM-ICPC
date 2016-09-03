//POJ1847 Tram floydÀ„∑® p[i][j] = min(p[i][j], p[i][k] + p[k][j])
#include <iostream>
#include <cstring>
#include <cstdio>
#define V 120
using namespace std;

int p[V][V];
int n, m, a, b;
const int INF = 0xfffffff;

int main()
{
	int k, i, j, u;
	while (scanf("%d%d%d", &n, &a, &b) != EOF)
	{
		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j++)
			  p[i][j] = p[j][i] = INF;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			for (j = 1; j <= m; j++)
			{
			  scanf("%d", &u);
			  p[i][u] = (j == 1? 0:1);
			}
		}

		for (k = 1; k <= n; k++)
		{
			for (i = 1; i <= n; i++)
			{
				if (p[i][k] == INF) continue;
				for (j = 1; j <= n; j++)
				{
					if (p[k][j] == INF) continue;
					p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
				}
			}
		}
		printf("%d\n", (p[a][b] == INF? -1:p[a][b] ));
	}
	return 0;
}
		
