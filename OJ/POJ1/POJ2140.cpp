#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n,ans,i;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		for(i=1;i<n;i+=2)
		{
			if(n%i==0)
			  ans++;
		}
		if(n%2)
		  ans++;
		printf("%d\n",ans);
	}
	return 0;
}

