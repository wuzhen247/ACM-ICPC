#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000005
using namespace std;
int p[N],np,o[N];
bool prime[N];
int main()
{
	int i,j,n;
	long long sum;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=0,np=0;
	for(i=2;i<N;i++)
	{
		if(prime[i])
		{
			p[np++]=i;
			o[i]=i-1;
		}
		for(j=0;j<np&&p[j]*i<N;j++)
		{
			prime[i*p[j]]=false;
			if(i%p[j]==0)
			{
				o[i*p[j]]=o[i]*p[j];
				break;
			}
			else
			  o[i*p[j]]=o[i]*(p[j]-1);
		}
	}
	while(scanf("%d",&n)&&n)
	{
		sum=0;
		for(j=1;j<=n;j++)
		  sum+=o[j];
		printf("%I64d\n",sum);
	}
	return 0;
}
