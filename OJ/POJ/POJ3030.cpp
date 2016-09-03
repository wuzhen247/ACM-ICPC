#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,r,e,c,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&r,&e,&c);
		temp=e-c;
		if(r<temp)
		  printf("advertise\n");
		else if(r==temp)
		  printf("does not matter\n");
		else
		  printf("do not advertise\n");
	}
	return 0;
}
