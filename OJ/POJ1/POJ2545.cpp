#include<iostream>
#include<cstdio>
using namespace std;
long long a[100001];
long long min(long long a,long long b,long long c)
{
	long long temp=a>b?b:a;
	return temp>c?c:temp;
}
int main()
{
	long long p1,p2,p3,n;
	int r1,r2,r3;
	a[0]=1;
	while(scanf("%lld%lld%lld%lld",&p1,&p2,&p3,&n)!=EOF)
	{
		r1=r2=r3=0;
		for(int i=1;i<100001;i++)
		{
			a[i]=min(a[r1]*p1,a[r2]*p2,a[r3]*p3);
			if(a[i]==a[r1]*p1)
			  r1++;
			if(a[i]==a[r2]*p2)
			  r2++;
			if(a[i]==a[r3]*p3)
			  r3++;
		}
		printf("%lld\n",a[n]);
	}
	return 0;
}
