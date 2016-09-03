//约瑟夫环问题
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,m,i,y;
	while(scanf("%d%d%d",&n,&k,&m)&&n||k||m)
	{
		y=0;
		for(i=2;i<n;i++)
		  y=(y+k)%i;
		y=(y+m)%n+1;
		printf("%d\n",y);
	}
	return 0;
}
