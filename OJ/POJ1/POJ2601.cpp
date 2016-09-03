#include<iostream>
#include<cstdio>
using namespace std;

double c[3100],a,b;
int n;
int main()
{
	int i,j;
	double ans;
	
	scanf("%d%lf%lf",&n,&a,&b);
	for(i=1;i<=n;i++)
	  scanf("%lf",&c[i]);
	ans=b+n*a;
	for(i=2,j=n;j>0;j--,i+=2)
	  ans-=i*c[j];
	ans/=(n+1);
	printf("%.2lf\n",ans);
	return 0;
}
