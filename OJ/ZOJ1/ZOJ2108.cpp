#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a[101],i,sum;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&a[0]);
		sum=a[0]*6+5;
		
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>=a[i-1])
			  sum+=(a[i]-a[i-1])*6+5;
			else if(a[i]<a[i-1])
			  sum+=(a[i-1]-a[i])*4+5;
		}
		printf("%d\n",sum);
	}
	return 0;
}

