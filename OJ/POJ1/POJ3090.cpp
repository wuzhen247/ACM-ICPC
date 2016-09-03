//¼ÆËãÅ·À­º¯Êý
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1005
int p[N],np,o[N];
bool prime[N];
int main()
{
	int t,n,i,j,sum;
	memset(prime,true,sizeof(prime));
	np=0,o[1]=1;
	for(i=2;i<N;i++)
	{
		if(prime[i])
		{
			p[np++]=i;
			o[i]=i-1;
		}
		for(j=0;j<np&&p[j]*i<N;j++)
		{
			prime[p[j]*i]=false;
			if(i%p[j]==0)
			  o[i*p[j]]=o[i]*p[j];
			else
			  o[i*p[j]]=o[i]*(p[j]-1);
		}
	}
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		  sum+=o[j];
		printf("%d %d %d\n",i,n,sum*2+1);
	}
	return 0;
}


