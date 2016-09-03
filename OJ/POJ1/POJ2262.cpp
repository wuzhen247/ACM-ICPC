#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000005
bool prime[N];
int main()
{
	int n,i,j;
	bool flag;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(i=2;i<N;i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<N;j+=i)
			  prime[j]=false;
		}
	}
	while(scanf("%d",&n)&&n)
	{
		flag=false;
		if(prime[2]&&prime[n-2])
		{
			printf("%d = %d + %d\n",n,2,n-2);
			continue;
		}
		for(i=3;i+i<=n;i+=2)
		{
			if(prime[i]&&prime[n-i])
			{
				printf("%d = %d + %d\n",n,i,n-i);
				flag=true;
				break;
			}
		}
		if(flag==false)
		  printf("Goldbach's conjecture is wrong.\n");   
	}
	return 0;
}
