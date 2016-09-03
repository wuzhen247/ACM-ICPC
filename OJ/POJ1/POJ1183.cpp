//数学公式
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	__int64 a,m,n;
	scanf("%lld",&a);
	for(m=a;m>=1;m--)
	  if((a*a+1)%m==0)
		break;
	n=(a*a+1)/m;
	printf("%lld\n",2*a+m+n);
	return 0;
}
