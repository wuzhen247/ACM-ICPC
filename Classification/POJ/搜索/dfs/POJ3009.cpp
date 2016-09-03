//dfs 丢冰壶
#include <iostream>
#include <cstdio>
using namespace std;

int a[22][22], w, h, ans;
int dir[4][2]={{-1,0}, {0,-1}, {1,0}, {0,1}};

void dfs(int x, int y, int step)
{
	int nx, ny, tx, ty, px, py;
	if (step > 10)	return;
	if (a[x][y] == 3)
	{
		ans = min(ans, step);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		nx = x, ny = y;
		while (tx >= 1 && tx <= w && ty >= 1 && ty <= h && a[tx][ty] != 1)
		{
			nx += dir[i][0];
			ny += dir[i][1];
			if (a[nx][ny] == 3)
			{
				ans = min(ans, step);
				return;
			}
			tx = nx + dir[i][0];
			ty = ny + dir[i][1];
			if (tx<1 || tx>w || ty<0 || ty>h)
				break;
			if (a[tx][ty] == 1)
			{
				a[tx][ty] = 0;
				dfs(nx, ny, step+1);
				a[tx][ty] = 1;
			}
		}
	}
}

int main()
{
	int sx, sy;
	while (scanf("%d%d", &h, &w) && (w||h))
	{
		ans = 10000;
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
			{
				scanf("%d", &a[i][j]);
				if (a[i][j] == 2)
					sx = i, sy = j;
			}
		dfs(sx, sy, 1);
		if (ans <= 10)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}