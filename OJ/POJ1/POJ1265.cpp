//pick∂®¿Ì
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Point
{
	int x,y;
};
Point p[105];
int n;
double getArea()
{
	int i=0;
	double area=0;
	for(i=0;i<n;i++)
	  area+=p[i].x*p[(i+1)%n].y-p[(i+1)%n].x*p[i].y;
	area+=p[n].x*p[0].y-p[0].x*p[n].y;
	return fabs(area/2.0);
}
int gcd(int x,int y)
{
	if(y==0)
	  return x;
	return gcd(y,x%y);
}
inline int get(Point p1,Point p2)
{
	int a=abs(p2.x-p1.x);
	int b=abs(p2.y-p1.y);
	if(a==0&&b==0)
	  return 0;
	if(a==0)
	  return b-1;
	if(b==0)
	  return a-1;
	return gcd(a,b)-1;
}
int getOn()
{
	int i,sum=0;
	for(i=0;i<n;i++)
		sum+=get(p[i],p[(i+1)%n]);
//	sum+=get(p[n],p[0]);
	return n+sum;
}
int main()
{
	int i,t,in,on,j=0;
	double area;
	scanf("%d",&t);
	p[0].x=p[0].y=0;
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
		  scanf("%d%d",&p[i].x,&p[i].y);
		  p[i].x+=p[i-1].x,p[i].y+=p[i-1].y;
		}
		cout<<p[n].x<<' '<<p[n].y<<endl;
		area=getArea();
		on=getOn();
		in=area+1-on/2;
		printf("Scenario #%d:\n%d %d %.1llf\n\n",++j,in,on,area);
	}
	return 0;
}

