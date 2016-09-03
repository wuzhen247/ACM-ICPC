//Õ·×ªÏà³ý·¨
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int t,l,r,a,b,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Scenario #%d:\n",i);
		scanf("%d%d",&l,&r);
		a=b=0;
		while(l!=r)
		{
			if(l>r)
			{
				a+=(l-1)/r;
				l-=(l-1)/r*r;
			}
			else
			{
				b+=(r-1)/l;
				r-=(r-1)/l*l;
			}
		}
		printf("%d %d\n\n",a,b);
	}
	return 0;
}

