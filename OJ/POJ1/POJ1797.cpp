#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1005][1005],n,m,dp[1005];
bool vis[1005];

void Dij(int t)
{
	memset(vis,0,sizeof(vis[0])*(n+4));
	for(int i=1;i<=n;i++)
	  dp[i]=a[t][i];
	dp[t]=1000005,vis[t]=true;
	for(int i=1;i<n;i++)
	{
		int k=t,temp=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if(dp[j]>=temp)
			{
				temp=dp[j];
				k=j;
			}
		}
		vis[k]=true;
		if(vis[n]) return;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			dp[i]=max(dp[i],min(dp[k],a[k][i]));
		}
	}
}
int main()
{
	int t,tcase;
	scanf("%d",&tcase);
	for(t=1;t<=tcase;t++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			memset(a[i],0,sizeof(a[i][0])*(n+4));
		for(int j=0;j<m;j++)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			a[u][v]=a[v][u]=max(a[u][v],c);
		}
		Dij(1);
		printf("Scenario #%d:\n",t);
		printf("%d\n\n",dp[n]);
	}
	return 0;
}
