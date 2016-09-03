#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	double s;
	int n,i;
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF)
	{
		s=0;
		for(i=1;i<=n;i++)
		  s+=1.0/(i+i);
		printf("%5d %9.3lf\n",n,s);
	}
	return 0;
}

