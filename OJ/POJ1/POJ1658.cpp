#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[4],t,i;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<4;i++)
		  scanf("%d",&a[i]);
		if((a[1]+a[3])==2*a[2])
		{
			for(i=0;i<4;i++)
			  printf("%d ",a[i]);
			printf("%d\n",2*a[3]-a[2]);
		}
		else
		{
			for(i=0;i<4;i++)
			  printf("%d ",a[i]);
			printf("%d\n",a[3]*a[3]/a[2]);
		}
	}
	return 0;
}
