//计算n以内的平方数个数
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)sqrt(n));
	}
	return 0;
}
