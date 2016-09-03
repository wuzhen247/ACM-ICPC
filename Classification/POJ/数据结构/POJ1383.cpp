//Labyrinth 迷宫 类似树的直径 两次bfs
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010;

struct Point
{
	int x, y, d;
}s, map[1010];

int dir[4][2]={0,1,1,0,0,-1,-1,0};
bool flag[N][N];
int n, m, Max, ax, ay;
char g[N][N];

void bfs()
{
	Max = 0;
	memset(flag, false, sizeof(flag));
	flag[s.x][s.y] = true;
	queue<Point>q;
	q.push(s);
	while(!q.empty())
	{
		Point fr = q.front();
		q.pop();
		for (int i =0; i < 4; i++)
		{
			Point tm;
			tm.x = fr.x+dir[i][0];
			tm.y = fr.y+dir[i][1];
			if (tm.x < 1|| tm.x > n || tm.y < 1|| tm. y > m || flag[tm.x][tm.y] || g[tm.x][tm.y] =='#')
				continue;
			tm.d = fr.d+1;
			flag[tm.x][tm.y] = true;
			if (tm.d > Max)
			{
				Max = tm.d;
				ax = tm.x, ay = tm.y;
			}
			q.push(tm);
		}
	}
}

int main()
{
	int t, i, j, k, a, b;
	scanf("%d", &t);
	while (t--)
	{
		bool f = false;
		scanf("%d%d", &m, &n);
		for (i = 1; i <= n; i++)
			scanf("%s",g[i]+1);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (g[i][j] == '.')
				{
					f = true;
					a = i;
					b = j;
					break;
				}
			}
			if (f)	break;
		}
		s.x = a, s.y = b, s.d = 0;
		bfs();
		s.x = ax, s.y = ay, s.d = 0;
		bfs();
		printf("Maximum rope length is %d.\n",Max);
	}
}