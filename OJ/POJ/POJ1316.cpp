#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool a[10005];
int main()
{
	int i,sum,temp;
	memset(a,true,sizeof(a));
	for(i=1;i<=10000;i++)
	{
		sum=0,temp=i;
		while(temp)
		{
			sum+=temp%10;
			temp/=10;
		}
		sum+=i;
		a[sum]=false;
	}
	for(i=1;i<=10000;i++)
	{
		if(a[i]==true)
		  printf("%d\n",i);
	}
	return 0;
}

		
