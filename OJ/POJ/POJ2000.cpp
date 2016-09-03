#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,sum,i,temp;
	while(scanf("%d",&n)&&n!=0)
	{
		sum=0;
		for(i=0,temp=0;temp<n;)
		{
			i++;
			temp+=i;
			sum+=i*i;
		}
		sum=sum-i*i+i*(n-temp+i);
		printf("%d %d\n",n,sum);
	}
	return 0;
}

