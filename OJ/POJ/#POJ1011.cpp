//复原小木棍的长度 
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
bool vis[66];
int a[66],sum,ave,n,m;
bool cmp(int a,int b)
{
	return a>b;
}
bool dfs(int len,int num,int s)
{
	if(num==m)
	  return true;
	int last=-1;
	for(int i=s;i<n;i++)
	{
		if(vis[i]||a[i]==last)
		  continue;
		vis[i]=true;
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
		vis[i]=false;
		if(len==0)
			break;
	}
	return false;
}
int main()
{
	int i;
	bool flag;
	while(scanf("%d",&n)&&n)
	{
		for(sum=0,i=0;i<n;i++)
		{
			scanf("%d",a+i);
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		memset(vis,false,sizeof(vis));
		flag=false;
		for(ave=a[0];ave<=sum-a[0];ave++)
		{
			if(sum%ave==0)
			{
				m=sum/ave;
				if(dfs(0,0,0))
				{
					printf("%d\n",ave);
					flag=true;
					break;
				}
			}
		}
		if(flag==false)
			cout<<sum<<endl;
	}
	return 0;
}
