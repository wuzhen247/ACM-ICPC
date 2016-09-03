//计算11111的···11的为n的倍数的最小位数
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,i,num,sum,a;
	while(scanf("%d",&n)!=EOF)
	{
		num=1,sum=1,a=1;
		while(sum%n!=0)
		{
			a*=10;
			num++;
			a%=n;
			sum+=a;
		}
		printf("%d\n",num);
	}
	return 0;
}
