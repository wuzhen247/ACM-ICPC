#include<iostream>
#include<cstdio>
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	long long d=exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-a/b*y;
	return d;
}
int main()
{
	long long A,B,C,k,x,y;
	while(scanf("%I64d%I64d%I64d%I64d",&A,&B,&C,&k)&&(A||B||C||k))
	{
		long long a=C,b=B-A,n=1LL<<k;
		long long d=exgcd(a,n,x,y);
		if(b%d)
		printf("FOREVER\n");
		else
		{
			x=(x*(b/d))%n;
			x=(x%(n/d)+n/d)%(n/d);
			printf("%I64d\n",x);
		}
	}
	return 0;
}
