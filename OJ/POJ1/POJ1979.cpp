//dfs
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,ans;
char map[25][25];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};

bool isInmap(int x,int y)
{
	if(x>=0&&x<m&&y>=0&&y<n)
		return true;
	return false;
}

void dfs(int x,int y)
{
	map[x][y]='#';
	ans++;
	int mx=x,my=y,i;
	for(i=0;i<4;i++)
	{
		int dx=mx+dir[i][0];
		int dy=my+dir[i][1];
		if(isInmap(dx,dy)&&map[dx][dy]!='#')
			dfs(dx,dy);

	}
	return;
}

int main()
{
	int i,j,x,y;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		for(i=0;i<m;i++)
			scanf("%s",map[i]);
		ans=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(map[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
		dfs(x,y);
		printf("%d\n", ans);
	}
}