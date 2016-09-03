//天平平衡 dp
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int dp[22][15002];
int c[22];
int g[22];

int main()
{
	int C,G,i,j,k;
	scanf("%d%d",&C,&G);
	for(i=1;i<=C;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=G;i++)
		scanf("%d",&g[i]);
	
	memset(dp,0,sizeof(dp));
	dp[0][7500]=1;

	for(i=1;i<=G;i++)
	{
		for(j=1;j<=15000;j++)
			if(dp[i-1][j])
			for(k=1;k<=C;k++)
				dp[i][j+g[i]*c[k]]+=dp[i-1][j];
	}

	printf("%d\n",dp[G][7500]);
	return 0;
}