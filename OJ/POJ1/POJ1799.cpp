#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);

int main()
{
	int t,n,i;
	double R,r;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lf%d",&R,&n);
		r=R/(1.0+1.0/sin(pi/(double)n));
		printf("Scenario #%d:\n", i);
		printf("%.3f\n\n", r);
	}
	return 0;
}