//素数距离，二次筛选 
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000
using namespace std;
const int N=50000; 
int prime1[N],nprime1,prime2[INF],l,r,nprime2;
bool isprime[INF];
void make_prime1()
{
	int i,j;
	nprime1=0;
	memset(isprime,true,sizeof(isprime));
	for(i=2;i<N;i++)
	{
		if(isprime[i])
		{
			prime1[++nprime1]=i;
			for(j=i+i;j<N;j+=i)
			  isprime[j]=false;
		}
	}
}
void make_prime2()
{
	long long i,j,b;
	memset(isprime,true,sizeof(isprime));
	for(i=1;i<=nprime1&&prime1[i]*prime1[i]<=r;i++)
	{
		b=l/prime1[i];
		while(b*prime1[i]<l||b<1)
			b++;
		if(b==1)
			b++;
		for(j=b*prime1[i];j<=r;j+=prime1[i])
		{
				isprime[j-l]=0;
		}
	}
	if(l==1)
		isprime[0]=0;
}
int main()
{
	int i,j,minl,minr,maxl,maxr,min,max;
	make_prime1();
	while(scanf("%d%d",&l,&r)!=EOF)
	{
		make_prime2();
		min=INF,max=-INF;
		nprime2=0;
		for(i=0;i<=r-l;i++)
			if(isprime[i])
				prime2[++nprime2]=i+l;
		if(nprime2<=1)
			printf("There are no adjacent primes.\n");
		else
		{										
			for(i=1;i<nprime2;i++)
			{
				if(prime2[i+1]-prime2[i]>max)
				{
					max=prime2[i+1]-prime2[i];
					maxl=prime2[i],maxr=prime2[i+1];
				}
				if(prime2[i+1]-prime2[i]<min)
				{
					min=prime2[i+1]-prime2[i];
					minl=prime2[i],minr=prime2[i+1];
				}
			}
			printf("%d,%d are closest, %d,%d are most distant.\n",minl,minr,maxl,maxr);
		}
	}
	return 0;
}
