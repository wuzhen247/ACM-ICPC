//快速幂取模
#include<iostream>
#include<cstdio>
using namespace std;
long long multimod(long long a,long long n,long long m)
{
	long long tm=a,res=1LL;
	while(n)
	{
		if(n&1)
		{
			res*=tm;
			res%=m;
		}
		tm=tm*tm%m;
		n>>=1;
	}
	return res;
}
int main()
{
	int t,i,num;
	long long s,a,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&m);
		scanf("%d",&num);
		s=0;
		while(num--)
		{
			scanf("%I64d%I64d",&a,&n);
			s+=multimod(a,n,m);
			if(s>=m)
			  s%=m;
		}
		printf("%I64d\n",s);
	}
	return 0;
}

