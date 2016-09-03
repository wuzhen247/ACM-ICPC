#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[30];
int main()
{
	int n,i,temp,num;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&a[0]);
		num=1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp!=a[num-1])
			{
				a[num++]=temp;
			}
		}
		for(i=0;i<num;i++)
		  printf("%d ",a[i]);
		printf("$\n");
	}
	return 0;
}
