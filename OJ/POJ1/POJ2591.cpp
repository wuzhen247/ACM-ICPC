#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10000005];
int main()
{
	int n,i,p1,p2;
	a[1]=1;
	p1=p2=1;
	for(i=2;i<10000005;i++)
	{
		a[i]=min(a[p1]*2+1,a[p2]*3+1);
		if(a[i]==a[p1]*2+1)
		  p1++;
		if(a[i]==a[p2]*3+1)
		  p2++;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}
