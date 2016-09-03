#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main()
{
	int n,i,j,year;
	double x,y,temp;
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		scanf("%lf%lf",&x,&y);
		temp=pi*(x*x+y*y)/2;
		year=int(temp/50)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",j,year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
