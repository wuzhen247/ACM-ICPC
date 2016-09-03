//计算半圆内最多点数，o^2复杂度，向量计算
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

struct node
{
	double x,y;
}map[155];

int n;
double point_x,point_y,point_r;

double Distance(double a,double b)
{
	return sqrt((point_x-a)*(point_x-a)+(point_y-b)*(point_y-b));
}

double mul(int a,int b)
{
	double x1,x2,y1,y2;
	x1=map[a].x-point_x;
	y1=map[a].y-point_y;
	x2=map[b].x-point_x;
	y2=map[b].y-point_y;
	return (x1*y2)-(x2*y1);
}

int main()
{
	int i,j,len,max;
	double m,a,b;
	while(scanf("%lf%lf%lf",&point_x,&point_y,&point_r),point_r>0)
	{
		scanf("%d",&n);
		for(i=0,j=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			m=Distance(a,b);
			if((m<point_r)||(m-point_r<1e-10))
			{
				map[j].x=a;
				map[j++].y=b;
			}
		}
		len=j,max=0;
		for(i=0;i<len;i++)
		{
			a=b=0;
			for(j=0;j<len;j++)
			{
				m=mul(i,j);
				if(m>0)		a++;
				else if(m<0)	b++;
				else	{ a++,b++;}
			}
			if(max<a)	max=(int)a;
			if(max<b)	max=(int)b;
		}
		printf("%d\n",max);
	}
	return 0;
}
