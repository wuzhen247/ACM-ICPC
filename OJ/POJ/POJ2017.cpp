#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[12][2],n,sum,i;
	while(scanf("%d",&n)&&n!=-1)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i][0],&a[i][1]);
		sum=a[0][0]*a[0][1];
		for(i=1;i<n;i++)
		  sum+=a[i][0]*(a[i][1]-a[i-1][1]);
		printf("%d miles\n",sum);
	}
	return 0;
}
