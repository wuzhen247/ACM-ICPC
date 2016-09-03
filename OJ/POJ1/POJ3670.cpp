#include<iostream>
#include<cstring>
#include<cstdio>
#define N 30002
using namespace std;
int a[N],dp[5];
int main()
{
	int n,i,j,ans,tm;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		tm=a[i];
		for(j=tm;j<=3;j++)
		  dp[tm]=max(dp[tm],dp[j]+1);
	}
	ans=max(dp[1],max(dp[2],dp[3]));
	memset(dp,0,sizeof(dp));
	for(i=n;i>=1;i--)
	{
		tm=a[i];
		for(j=tm;j>=1;j--)
		  dp[tm]=max(dp[tm],dp[j]+1);
	}
	for(i=1;i<=3;i++)
	  ans=max(ans,dp[i]);
	printf("%d\n",n-ans);
	return 0;
}
