#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double ka,acid,res,temp,delta;
int main()
{
	int m,n;
	while(scanf("%lf%lf%d%d",&ka,&acid,&m,&n)&&(ka||acid||m||n))
	{
		delta=sqrt(ka*ka+4*n*acid*ka*m);
		temp=(-ka+delta)/(2*n);
		res=-log10(temp);
		printf("%.3lf\n",res);
	}
	return 0;
}
