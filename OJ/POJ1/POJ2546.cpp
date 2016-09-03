//求圆与圆相交面积
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define pi acos(-1.0)
using namespace std;
int main()
{
	double x1,y1,a,x2,y2,b,c,s,ans,tm1,tm2;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&a,&x2,&y2,&b);
	if(a<b)
	  swap(a,b);
	c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	ans=0;
	if(c<=a-b)
	  ans=pi*b*b;
	else if(c>(a-b)&&c<(a+b))
	{
		tm1=acos((a*a+c*c-b*b)/(2*a*c));
		tm2=acos((b*b+c*c-a*a)/(2*b*c));
		s=(a+b+c)/2;
		s=sqrt(s*(s-a)*(s-b)*(s-c));
		ans=tm1*a*a+tm2*b*b-2*s;
	}
	printf("%.3lf",ans);
	return 0;
}
