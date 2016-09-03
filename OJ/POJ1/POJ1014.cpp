#include<iostream>
#include<cstdio>
using namespace std;
int a[7],sum,half;
bool flag;

void dfs(int s,int num)
{
	if(flag==true)
	  return;
	if(s==half)
	{
		flag=true;
		return;
	}
	for(int i=num;i>0;i--)
	{
		if(a[i]>0)
		{
			if(s+i<=half)
			{
				a[i]--;
				dfs(s+i,i);
				if(flag==true)
				  return;
			}
		}
	}
	return;
}

int main()
{
	int i,n=1;
	while(scanf("%d%d%d%d%d%d",a+1,a+2,a+3,a+4,a+5,a+6))
	{
		for(i=1,sum=0;i<=6;i++)
			sum+=a[i]*i;
		if(sum==0)
		  break;
		if(sum%2==1)
		{
			printf("Collection #%d:\nCan't be divided.\n\n",n++);
			continue;
		}
		half=sum/2;
		flag=false;
		dfs(0,6);
		if(flag)
			printf("Collection #%d:\nCan be divided.\n\n",n++);
		else
		  printf("Collection #%d:\nCan't be divided.\n\n",n++);
	}
	return 0;
}

	

