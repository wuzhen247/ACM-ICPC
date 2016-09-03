//gcd(i,n)之和，欧拉函数，积性函数性质
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000005
using namespace std;

int p[N],np;
bool prime[N];

void getprime()
{
	int i,j;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=0,np=0;
	for(i=2;i<N;i++)
	{
		if(prime[i])
		  p[np++]=i;
		for(j=0;j<np&&i*p[j]<N;j++)
		{
			prime[i*p[j]]=false;
			if(i%p[j]==0)
			  break;
		}
	}
}

int main()
{
	long long n,i,j,sum,num;
	getprime();
	while(scanf("%I64d",&n)!=EOF)
	{
		num=0,sum=n;
		for(i=0;i<np&&p[i]*p[i]<=n;i++)
		{
			if(n%p[i]==0)
			{
				num=0;
				while(n%p[i]==0)
				{
					n/=p[i];
					num++;
				}
				sum=sum+sum/p[i]*num*(p[i]-1);
			}
		}
		if(n>1)
		  sum=sum/n*(2*n-1);
		printf("%I64d\n",sum);
	}
	return 0;
}
