//C(n,m)的因子个数
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int p[500],np;
bool prime[500];

void getprime()
{
	memset(prime,true,sizeof(prime));
	int i,j;
	np=0;
	prime[0]=prime[1]=0;
	for(i=2;i<500;i++)
	{
		if(prime[i])
			p[np++]=i;
		for(j=0;j<=np&&p[j]*i<500;j++)
		{
			prime[p[j]*i]=false;
			if(i%p[j]==0)
				break;
		}
	}
}

int cal(int n,int k)
{
	if(n<k)
		return 0;
	else
		return n/k+cal(n/k,k);
}

int main()
{
	getprime();
	long long ans;
	int n,m,i,j;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=1LL;
		for(i=0;i<np&&p[i]<=n;i++)
		{
			ans*=cal(n,p[i])-cal(n-m,p[i])-cal(m,p[i])+1LL;
		}
		printf("%lld\n",ans );
	}
	return 0;
}