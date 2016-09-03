#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,i,a,b;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&a,&b);
		a=a*b;
		if(a%2)
		  printf("Scenario #%d:\n%d.41\n\n",i,a);
		else
          printf("Scenario #%d:\n%d.00\n\n",i,a);
    }
	return 0;
}
		

