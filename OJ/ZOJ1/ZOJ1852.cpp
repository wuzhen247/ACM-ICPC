#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main()
{
    double a,b,s,m,n,A,v;
    while(scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n)&&(a||b||s||m||n))
    {
        A=atan((n*b)/(m*a));
        v=(n*b)/(s*sin(A));
        A=A*180/pi;
        printf("%.2lf %.2lf\n",A,v);
    }
    return 0;
}
