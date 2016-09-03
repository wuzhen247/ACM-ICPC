//给定木棍拼正方形 
#include<cstdio>
#include<algorithm>
using namespace std;
int ave,n;
int a[22];
bool visit[22];
bool cmp(int a,int b)
{
	return a>b;
}
bool dfs(int len,int num,int id)
{
	if(num==3)
	  return true;
	int last=-1;
	for(int i=id;i<n;i++)
	{
		if(visit[i]||a[i]==last)
		  continue;
		visit[i]=true;
		if(len+a[i]<ave)
		{
			if(dfs(len+a[i],num,i+1))
			  return true;
		}
		if(len+a[i]==ave)
		{
			if(dfs(0,num+1,0))
			  return true;
		}
		last=a[i];
		visit[i]=false;
	}
	return false;
}
int main()
{
	int t,i,j,k,sum;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			visit[i]=false;
			sum+=a[i];
		}
		if(n<4||sum%4!=0)
		{
			printf("no\n");
			continue;
		}
		sort(a,a+n,cmp);
		ave=sum/4;
		if(a[0]>ave)
		{
			printf("no\n");
			continue;
		}
		if(dfs(0,0,0))
		  printf("yes\n");
		else
		  printf("no\n");
	}
	return 0;
}

