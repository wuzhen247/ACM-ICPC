#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,j,k,n,a[1005],max,temp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
			scanf("%d",a+j);
		sort(a+1,a+n+1);
		max=0;
		for(j=1,k=n;j<=n;j++,k--)
		{
			temp=a[j]*k;
			if(temp>max)
			  max=temp;
		}
		printf("%d\n",max);
	}
	return 0;
}

