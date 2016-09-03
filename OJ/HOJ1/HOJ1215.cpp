//计算n的所有因子之和
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500005
using namespace std;
int a[N];
int main()
{
	int t,n,i,j;
	for(i=2;i<N;i++)
	  a[i]=1;
	for(i=2;i<250002;i++)
	{
	  for(j=i+i;j<N;j+=i)
	  {
		a[j]+=i;
	  }
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
