//POJ2311 «–÷Ω∆¨ sg«Û∑®
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int w, h, sg[210][210];

int dfs(int n, int m)
{
	if (sg[n][m] != -1)
	  return sg[n][m];
	bool vis[40000];
	memset(vis, false, sizeof(vis));
	int i;
	for (i = 2; i <= n-i; i++)
	  vis[dfs(i,m)^dfs(n-i,m)] = true;
	for (i = 2; i <= m-i; i++)
	  vis[dfs(n,i)^dfs(n,m-i)] = true;
	for (i = 0; ; i++)
	  if (vis[i] == false)
		return sg[n][m] = i;
}

int main()
{
	memset(sg,-1,sizeof(sg));
	for (int i = 1; i <= 200; i++)
	  sg[i][1] = sg[1][i] = 1;
	while (scanf("%d%d", &w, &h) != EOF)
	{
		if (dfs(w,h)==0)
		  printf("LOSE\n");
		else
		  printf("WIN\n");
	}
	return 0;
}
