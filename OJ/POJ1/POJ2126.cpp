#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int a[25],n,i;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	  scanf("%d",&a[i]);
	if(n<=1)
	  printf("YES\n");
	else if(n==2)
	{
		if(a[1]*a[1]-4*a[0]*a[2]<0)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	else
	  printf("NO\n");
	return 0;
}
