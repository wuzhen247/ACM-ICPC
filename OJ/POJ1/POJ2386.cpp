//DFS 计算池塘块数
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dir[8][2]={{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,-1},{-1,1},{1,1}};
int n,m;
char map[105][105];

bool inMap(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
		return true;
	return false;
}

void dfs(int x,int y)
{
	map[x][y]='.';
	int mx=x,my=y,i;
	for(i=0;i<8;i++)
	{
		int dx=mx+dir[i][0];
		int dy=my+dir[i][1];
		if(inMap(dx,dy)&&map[dx][dy]=='W')
		{
			dfs(dx,dy);
		}
	}
	return ;
}

int main()
{
	int i,j,ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",map[i]);
	ans=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(map[i][j]=='W')
			{
				dfs(i,j);
				ans++;
			}
		}
	printf("%d\n",ans);
	return 0;
}