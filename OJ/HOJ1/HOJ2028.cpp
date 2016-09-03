#include<iostream>
#include<cstdio>
using namespace std;
typedef long long _int64;
_int64 gcd(_int64 a,_int64 b)
{
	if(b==0) return a;
	return gcd(b,a%b);
} 
_int64 lcm(_int64 a,_int64 b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int n,i;
	_int64 t1,t2;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%I64d",&t1);
		for(i=1;i<n;i++)
		{
			scanf("%I64d",&t2);
			t1=lcm(t1,t2);
		}
		printf("%I64d\n",t1);
	}
	return 0;
}
