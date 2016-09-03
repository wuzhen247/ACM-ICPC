#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[12][5000];
int bit[20];
int A,B;

int dfs(int pos,int num,bool flag)
{
	if(pos<=-1) return num>=0;
	if(num<0) return 0;
	if(!flag&&dp[pos][num]!=-1)
	  return dp[pos][num];
	int ans=0;
	int end=flag?bit[pos]:9;
	for(int i=0;i<=end;i++)
	  ans+=dfs(pos-1,num-i*(1<<pos),flag&&i==end);
	if(!flag) dp[pos][num]=ans;
	return ans;
}

int F(int num)
{
	int i=0,ans=0;
	while(num)
	{
		ans+=(num%10)*(1<<i);
		i++;
		num/=10;
	}
	return ans;
}

int calc()
{
	int len=0,i;
	while(B)
	{
		bit[len++]=B%10;
		B/=10;
	}
	return dfs(len-1,F(A),1);
}

int main()
{
	int t,k;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	for(k=1;k<=t;k++)
	{
		scanf("%d%d",&A,&B);
		printf("Case #%d: %d\n",k,calc());
	}
	return 0;
}
