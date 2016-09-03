//连续自然数之和为n
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int t,tm,n,ans,i;
	double a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&tm,&n);
		ans=0;
		for(i=2;i<=70000;i++)
		{
			a=(2.0*n/i-i-1)/2;
			if(a>=0&&a==int(a)) 
				ans++;
			if(a<0)
			  break;
		}
		printf("%d %d\n",tm,ans);
	}
	return 0;
}
