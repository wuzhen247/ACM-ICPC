#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n,i,j,num;
	while(scanf("%I64d",&n)&&n)
	{
		num=n;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				num=(num/i)*(i-1);
				while(n%i==0) n/=i;
			}
		}
		if(n>1) num=num-num/n;
		printf("%I64d\n",num);
	}
	return 0;
} 
