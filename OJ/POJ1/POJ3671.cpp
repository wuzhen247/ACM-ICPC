#include<iostream>
#include<cstring>
#include<cstdio>
#define N 30005
using namespace std;
int a[N],dp[N][2];//dp[i][0]为i后1 的个数,dp[i][1]为i前0的个数
int main()
{
	int n,i,ans,num;//num is the number of 1
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(i=0,num=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		  num++;
	}
	if(a[0]==1) dp[0][0]=num-1;
	else dp[0][0]=num;
	dp[0][1]=0;
	for(i=1;i<n;i++)
	{
		dp[i][0]=dp[i-1][0];
		if(a[i]==1) dp[i][0]--;
		dp[i][1]=dp[i-1][1];
		if(a[i-1]==2) dp[i][1]++;
	}
	ans=0xFFFFFFF;
	for(i=0;i<n;i++)
	{
	  if(ans>dp[i][0]+dp[i][1])
		ans=dp[i][0]+dp[i][1];
	}
	printf("%d\n",ans);
	return 0;
}


