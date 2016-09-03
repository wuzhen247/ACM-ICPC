//求因子的因子个数立方和
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 5000003
using namespace std;
bool prime[N];
int p[N],nprime;
void getprime()
{
	int i,j;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	nprime=0;
	for(i=2;i<N;i++)
	{
		if(prime[i])
		  p[nprime++]=i;
		for(j=0;j<nprime&&i*p[j]<N;j++)
		{
			prime[p[j]*i]=false;
			if(i%p[j]==0)
			  break;
		}
	}
}
int main()
{
	int t,i,j,n,ans,tm;
	scanf("%d",&t);
	getprime();
	while(t--)
	{
		scanf("%d",&n);
		ans=1,tm=0;
		if(prime[n])
		{
			printf("9\n");
			continue;
		}
		for(i=0;p[i]*p[i]<=n;i++)
		{
			if(n%p[i]==0)
			{
				tm=0;
				while(n%p[i]==0)
				{
					tm++;
					n/=p[i];
				}
				ans=ans*(tm+2)*(tm+2)*(tm+1)*(tm+1)/4;
			}
		}
		if(prime[n])
		  ans*=9;
		printf("%d\n",ans);
	}
	return 0;
}

