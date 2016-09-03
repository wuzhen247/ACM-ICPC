#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double multi(double a,int n)
{
	double tm=a,ans=1;
	while(n)
	{
		if(n&1)
		  ans*=tm;
		tm*=tm;
		n>>=1;
	}
	return ans;
}
int main()
{
	int r,m,y;
	double t;
	while(scanf("%d%d%d",&r,&m,&y)==3)
	{
		t=1+r/100.0;
		t=multi(t,y);
		m=m*t;
		printf("%d\n",m);
	}
	return 0;
}
