//ì³²¨ÄÇÆõÊıÁĞ
#include<iostream>
#include<cstdio>
using namespace std;
int a[51];
int main()
{
	int i,t,n;
	a[0]=1,a[1]=2;
	for(i=2;i<51;i++)
		a[i]=a[i-1]+a[i-2];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n",i);
		printf("%d\n\n",a[n]);
	}
	return 0;
}

