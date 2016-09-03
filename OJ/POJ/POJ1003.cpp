#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i;
	double c,sum;
	while(scanf("%lf",&c)!=EOF)
	{
		if(c<0.01||c>5.20)
			continue;
		for(i=1,sum=0;sum<c;i++)
			sum+=1.0/(i+1);
		printf("%d card(s)\n",i-1);
	}
	return 0;
}
