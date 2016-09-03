#include<iostream>
#include<cstdio>
using namespace std;

int a[20],n,tm;

int main()
{
	int i,j,ans;
	while(scanf("%d",&tm)&&tm!=-1)
	{
		a[0]=tm;
		j=1;
		while(scanf("%d",&tm)&&tm)
		{
			a[j++]=tm;
		}
		n=j-1;
		ans=0;
		for(i=0;i<=n;i++)
		  for(j=0;j<=n;j++)
			if(a[j]/a[i]==2&&a[j]%a[i]==0)
			  ans++;
		printf("%d\n",ans);
	}
	return 0;
}
