#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int t,n,i;
	long long a[6],lcm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		  scanf("%I64d",&a[i]);
		}
		lcm=a[0];
		for(i=1;i<n;i++)
		{
			lcm=lcm/gcd(lcm,a[i])*a[i];
		}
		if(lcm<=1000000000)
		  printf("%I64d\n",lcm);
		else
		  printf("More than a billion.\n");
	}
	return 0;
}

