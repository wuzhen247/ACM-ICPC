//3*n 中放2*1方块
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[32];

int main()
{
	int i;
	a[0]=1,a[1]=3;
	for(i=2;i<31;i++)
		a[i]=4*a[i-1]-a[i-2];
	while(scanf("%d",&n)&&n!=-1)
	{
		if(n%2)
			printf("0\n");
		else
			printf("%d\n", a[n/2]);
	}
	return 0;
}