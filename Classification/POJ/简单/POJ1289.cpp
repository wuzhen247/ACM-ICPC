#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-7
using namespace std;

int main()
{
	long long a,b,m,n,i;
	while(scanf("%lld%lld",&a,&b)&&(a||b))
	{
	
		if(b==1)
		{
			i=0;
			while(a!=1)
			{
				i++;
				a/=2;
			}
			printf("%lld %lld\n",i,(long long)pow(2,(double)(i+1))-1);
			continue;
		}
		for(i=1;;i++)
		{
			m=pow(a,1.0/i)+eps;
			n=pow(b,1.0/i)+eps;
			if(m==(n+1)&&(long long)pow(m,(double)i)==a)//&&(long long)pow(n,(double)i)==b)
			  break;
		}
		printf("%lld %lld\n",(b-1)/(n-1),a*(n+1)-b*n);
	}
	return 0;
}
