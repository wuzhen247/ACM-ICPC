//反向拓扑，注意重量和序号
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 205;

int t, n, m, d[N], q[N], num;
bool map[N][N];

bool sol()
{
	int i, j, k;
	num = n;
	for (i = 1; i <= n; i++)
	{
		for (j = n; j >= 1; j--)
		{
			if (d[j] == 0)
			{
				d[j]--;
				q[j] = num--;
				for (k = 1; k <= n; k++)
				{
					if (k == j)	continue;
					if (map[j][k] == true)
						d[k]--;
				}
				break;
			}
		}
	}
	if (num == 0)
		return true;
	else
		return false;
}

int main()
{
	int u, v, i, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		memset(d, 0, sizeof(d));
		memset(map, false, sizeof(map));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			if (map[v][u] == false)
			{
				map[v][u] = true;
				d[u]++;
			}
		}
		if (sol())
		{
			for (i = 1; i < n; i++)
				printf("%d ", q[i]);
			printf("%d\n", q[i]);
		}
		else
			printf("-1\n");
	}
	return 0;
}