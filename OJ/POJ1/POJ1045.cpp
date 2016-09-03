#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double v,r,c,w;
	int n;
	scanf("%lf%lf%lf%d",&v,&r,&c,&n);
	while(n--)
	{
		scanf("%lf",&w);
		printf("%.3lf\n",v*r*c*w/sqrt(1+r*r*c*c*w*w));
	}
	return 0;
}
