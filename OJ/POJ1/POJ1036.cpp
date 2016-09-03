//强盗进门，求财富值
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool fg[30002];
int dp[2][102];
struct Gangsters
{
	int tt,p,s;
}g[102];

int main()
{
	int n,k,t,i,j,w,l,temp,Max;

	memset(fg,false,sizeof(fg));
	memset(dp,0,sizeof(dp));
	scanf("%d%d%d",&n,&k,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&g[i].tt);
		fg[g[i].tt]=true;
	}
	for(i=1;i<=n;i++)
	  scanf("%d",&g[i].p);
	for(i=1;i<=n;i++)
	  scanf("%d",&g[i].s);
	for(i=0;i<=t;i++)
	  for(j=0;j<=i&&j<=k;j++)
	  {
		  w=0;
		  if(fg[i]==true)
		  {
			  for(l=1;l<=n;l++)
				  if(g[l].tt==i&&g[l].s==j)
					w+=g[l].p;
		  }
			  temp=i%2;
			  if(j==0) 
				dp[temp][j]=max(dp[1-temp][j],dp[1-temp][j+1]);
			  else if(j==k)
				dp[temp][j]=max(dp[1-temp][j],dp[1-temp][j-1]);
			  else
				dp[temp][j]=max(max(dp[1-temp][j-1],dp[1-temp][j]),dp[1-temp][j+1]);
			  dp[temp][j]+=w;	  
		}
	temp=t%2,Max=0;
	for(i=0;i<=k;i++)
	  if(Max<dp[temp][i])
		Max=dp[temp][i];
	printf("%d\n",Max);
	return 0;
}

