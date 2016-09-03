#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t,j,m,n;
	double s,temp;
	temp=(double)sqrt(2.0);
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d%d",&m,&n);
		if(m*n%2)
		  s=m*n-1+temp;
		else
		  s=m*n;
		printf("Scenario #%d:\n%.2lf\n\n",j,s);
	}
	return 0;
}
