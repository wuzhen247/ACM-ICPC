//miller_rabin 素数测试
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

__int64 mod(__int64 a,__int64 n,__int64 p)
{
	__int64 tm=a%p,res=1LL;
	while(n)
	{
		if(n&1LL)
		{
			res*=tm;
			if(res>=p)
			{
				res%=p;
			}
		}
		tm*=tm;
		tm%=p;
		n>>=1LL;
	}
	return res;
}

bool miller_rabin(__int64 n)
{
	if(n==2 || n==3 || n==5 || n==7)
		return true;
	if(n==1 || n%2==0 ||n%3==0 ||n%5==0 ||n%7==0)
		return false;
	int t=20;
	while(t--)
	{
		if(mod(rand()%(n-1)+1,n-1,n)!=1)
			return false;
	}
	return true;
}

int main()
{
	__int64 p,a;
	while(scanf("%I64d%I64d",&p,&a)&&(p||a))
	{
		if(miller_rabin(p))
			printf("no\n");
		else if(mod(a,p,p)==a)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}