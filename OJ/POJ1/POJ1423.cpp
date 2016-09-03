#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
const double e=exp(1.0);
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		if(m==1) 
		{
			printf("1\n");
			continue;
		}
		n=(int)(log10(sqrt(2*pi*m))+m*log10(m/e)+1);
		printf("%d\n",n);
	};
	return 0;
}
