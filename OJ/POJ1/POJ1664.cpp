#include<iostream>
#include<cstdio>
using namespace std;
int digui(int m,int n)
{
	if(m==1||n==1||m==0)
	  return 1;
	else if(m<n)
	  return digui(m,m);
	else
	  return digui(m,n-1)+digui(m-n,n);
}
int main()
{
	int t,i,m,n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",digui(m,n));
	}
	return 0;
}
