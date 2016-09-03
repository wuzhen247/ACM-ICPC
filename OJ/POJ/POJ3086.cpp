#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int i,j,k,N,n,a[305],sum=0;
	for(i=1;i<=305;i++)
	{
		a[i]=i*(i+1)/2;
	}
	scanf("%d",&N);
	for(k=1;k<=N;k++)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		  sum+=i*a[i+1];
		printf("%d %d %d\n",k,n,sum);
	}
	return 0;
}
