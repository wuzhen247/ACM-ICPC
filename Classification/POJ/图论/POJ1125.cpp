//POJ1125 Stockbroker Grapevine floyd算法 前提：都能到达，求最大值中的最小值
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 110
using namespace std;

const int INF = 0xfffffff;
int a[N][N], n, m;

int main()
{
	int i, j, k, id, ma, MAX;
	bool f;
	while (scanf("%d", &n) && n)
	{
		for (i = 1; i <= n; i++)
		  for (j = 1; j <= n; j++)
			a[i][j] = INF;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			while (m--)
			{
				scanf("%d", &id);
				scanf("%d", &a[i][id]);
			}
		}

		for (k = 1; k <= n; k++)
		{
			for (i = 1; i <= n; i++)
			{
				if (a[i][k] == INF)
				  continue;
				for (j = 1; j <= n; j++)
				{
					if (a[k][j] == INF || i == j)
					  continue;
					a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
				}
			}
		}
		id = ma =-1;
		MAX = INF;
		for (i = 1; i <= n; i++)
		{
			f = true;
			for (j = 1; j <= n; j++)
			{
				if (i == j)
				  continue;
				if (a[i][j] == INF)
				{
					f = false;
					break;
				}
			}
			if (f)
			{
				ma = -1;
				for (j = 1; j <= n; j++)
				{
					if (i == j)	continue;
					if (a[i][j] > ma)
						ma =a[i][j];
				}
				if (MAX > ma)
				{
					MAX = ma;
					id  = i;
				}
			}
		}

		if (MAX == INF)
		  printf("disjoint\n");
		else
		  printf("%d %d\n",id, MAX);
	}
	return 0;
}
