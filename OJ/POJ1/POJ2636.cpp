#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,sum,i,a[12];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		sum=0;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",sum-k+1);
	}
	return 0;
}

