//注意：光标自动移动导致已经到达的状态可能需要重新到达
//BFS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 15;
int n, m, p, ans;
bool vis[N][N][5];
char g[15][15];
int sl[4] = {0, 1, 2, 3};
int sxy[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

struct Node
{
	int x, y, dir, step;
};

Node st, aim, tm, now;
queue<Node> q;

int main()
{

	int t;
	scanf("%d", &t);
	while (t--)
	{
		while (!q.empty())	q.pop();
		scanf("%d%d%d", &n, &m, &p);
		memset(g, 0, sizeof(g));
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++)
			scanf("%s", g[i]+1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (g[i][j] == '@')
					st.x = i, st.y = j;
				else if (g[i][j] == '$')
					aim.x = i, aim.y = j;
			}
		}

		ans = 0;
		vis[st.x][st.y][0] = true;
		st.step = st.dir = 0;
		q.push(st);
		bool flag = false;
		
		
		while (!q.empty() && flag == false)
		{
			now = q.front();
			q.pop();
			if (now.x == aim.x && now.y == aim.y)
			{
				ans = now.step;
				flag = true;
				break; 
			}	
			//turn right
			tm = now;
			tm.dir = (now.dir+1)%4;
			tm.step = now.step+1;
			if (tm.step % p == 0)
				tm.dir = (tm.dir+3) % 4;
			if (!vis[tm.x][tm.y][tm.dir])
			{	
				vis[tm.x][tm.y][tm.dir] = true;
				q.push(tm);
			}
			//turn left
			tm = now;
			tm.dir = (now.dir+3)%4;
			tm.step = now.step+1;
			if (tm.step % p == 0)
				tm.dir = (tm.dir+3) % 4;
			if (!vis[tm.x][tm.y][tm.dir])
			{
				vis[tm.x][tm.y][tm.dir] = true;
				q.push(tm);
			}
			//wait
			tm = now;
			tm.step = now.step+1;
			if (tm.step % p == 0)
				tm.dir = (tm.dir+3) % 4;
			if (!vis[tm.x][tm.y][tm.dir])
			{
				vis[tm.x][tm.y][tm.dir] = true;
				q.push(tm);
			}
			//move
			tm = now;
			tm.x = now.x + sxy[now.dir][0];
			tm.y = now.y + sxy[now.dir][1];
			tm.step = now.step+1;
			if ((g[tm.x][tm.y] == '.' || g[tm.x][tm.y] == '$'))
			{
				if (tm.x == aim.x && tm.y == aim.y)
				{
					ans = tm.step;
					flag = true;
					break; 
				}
				if (tm.step % p == 0)
					tm.dir = (tm.dir+3) % 4;
				if (!vis[tm.x][tm.y][tm.dir])
				{
					vis[tm.x][tm.y][tm.dir] = true;
					q.push(tm);
				}
			}
		}
		

		if (flag)
			printf("%d\n", ans);
		else
			printf("YouBadbad\n");
	}
	return 0;
}