#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Point
{
	double x,y;
};
Point p[1005];
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		  scanf("%lf%lf",&p[i].x,&p[i].y);
		printf("%d",n);
		for(i=0;i<n;i++)
		{
			printf(" %.6lf",(p[i].x+p[(i+1)%n].x)/2);
			printf(" %.6lf",(p[i].y+p[(i+1)%n].y)/2);
		}
		printf("\n");
	}
	return 0;
}

