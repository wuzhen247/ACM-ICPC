#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,i,sum,a[3000],half;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&n)&&n)
	{
		sum=0;
		printf("%5d  ", n); 
		if(n==1)
		{
			printf("DEFICIENT\n");
			continue;
		}
		half=n/2;
		for(i=1;i<=half;i++)
		{
			if(n%i==0)
				sum+=i;
		}
		if(sum==n)
		  printf("PERFECT\n");
		else if(sum>n)
		  printf("ABUNDANT\n");
		else
		  printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT");
	return 0;
}
