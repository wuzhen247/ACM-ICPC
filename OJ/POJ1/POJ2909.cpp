//线性筛求素数
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 32800

int p[N],np;
bool prime[N];

void doprime()
{
	int i,j;
	np=0;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=0;
	for(i=2;i<N;i++)\
	{
		if(prime[i])
			p[np++]=i;
		for(j=0;j<np&&p[j]*i<N;j++)
		{
			prime[i*p[j]]=false;
			if(i%p[j]==0)
				break;
		}
	}
}

int main()
{
	int n,ans,i,j;
	doprime();
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(i=0;p[i]<=n/2;i++)
		{
			if(prime[n-p[i]])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}