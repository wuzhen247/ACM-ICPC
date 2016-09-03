#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	while(scanf("%d",&n)&&n)
	{
		int p=(1<<((n-1960)/10+2));
		double sum=1.0;
		int k=1;
		for(i=1;i<=p;i++)
		{
			sum*=2.0;
			if(sum>k)
			{	
				sum/=k;
				k++;
			}
		}
		printf("%d\n",k-1);
	}
	return 0;
}
		
