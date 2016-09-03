//º∆À„º∏∫Œ
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
const double pi=acos(-1.0);
using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3,p,d,s,a,b,c;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
        b=sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
        c=sqrt((y3-y2)*(y3-y2)+(x3-x2)*(x3-x2));
        p=(a+b+c)/2.0;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        d=(a*b*c)/(2*s);
        printf("%.2lf\n",d*pi);
    }
    return 0;
}
