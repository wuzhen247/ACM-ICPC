//pick∂®¿Ì
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int x1,y,x2,y2,x3,y3;

int gcd(int a, int b)
{
	if (b==0)
	  return a;
	return gcd(b,a%b);
}

/*double getDis(double a, double b, double c, double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double getArea()
{
	double s1 = getDis(x1,y,x2,y2);
	double s2 = getDis(x2,y2,x3,y3);
	double s3 = getDis(x1,y,x3,y3);
	double p = (s1+s2+s3)/2;
	return sqrt(p*(p-s1)*(p-s2)*(p-s3));
}*/

double getArea()
{
	double tm = (x3-x1)*(y2-y) - (y3-y)*(x2-x1);
	if (tm < 0)
	  tm =-tm;
	return tm/2;
}
	
int main()
{
	double area;
	int a;
	while (scanf("%d%d%d%d%d%d",&x1,&y,&x2,&y2,&x3,&y3) && (x1||y||x2||y2||x3||y3))
	{
		area = getArea();
		a = 0;
		a += gcd(abs(x1-x2),abs(y-y2));
		a += gcd(abs(x1-x3),abs(y-y3));
		a += gcd(abs(x2-x3),abs(y2-y3));
		printf("%d\n", int(area+1-a/2.0));
	}
	return 0;
}
