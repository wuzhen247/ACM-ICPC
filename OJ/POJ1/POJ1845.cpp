//��a^b��Լ��֮��
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 50000
typedef long long ll;
using namespace std;
const int mod=9901;
int p[N],np,n;
bool prime[N];
ll a[10000],b[10000],A,B;
void getprime()
{
	int i,j;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=0;
	np=0;
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

void get()
{
	memset(b,0,sizeof(b));
	int i,tm;
	for(i=0,n=0;p[i]*p[i]<=A;i++)
	{
		if(A%p[i]==0)
		{
			a[n]=p[i];
			while(A%p[i]==0)
			{
				A/=p[i];
				b[n]++;
			}
			n++;
		}
	}
	if(A>1)
	  a[n]=A,b[n++]=1;
}
ll pow(ll a,ll k)
{
	ll p=a,ans=1;
	while(k)
	{
		if(k&1)
		  ans=ans*p%mod;
		p=p*p%mod;
		k>>=1;
	}
	return ans;
}
ll f(ll p,ll k)
{
	if(k==0) return 1;
	if(k&1) return ((f(p,k/2)%mod)*(1+pow(p,k/2+1)%mod))%mod;
	return ((f(p,k/2-1)%mod)*(1+pow(p,k/2+1)%mod))%mod+pow(p,k/2);
}

int main()
{
	ll sum,ans;
	int i,j;
	getprime();
	
	scanf("%I64d%I64d",&A,&B);
	get();
	sum=1;
	for(i=0;i<n;i++)
	{
		ans=f(a[i],B*b[i]);
		sum=sum*ans%mod;
	}
	printf("%I64d\n",sum);
	return 0;
}
	
