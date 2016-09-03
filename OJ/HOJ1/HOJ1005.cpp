#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t[52],a,b,n,i,j;
	t[1]=t[2]=1;
	while(scanf("%d%d%d",&a,&b,&n)&&(a||b||n))
	{
		t[3]=t[4]=0;
		for(i=3;i<50;i++)
		{
			t[i]=(a*t[i-1]+b*t[i-2])%7;
		}
		printf("%d\n",t[n%49]);
	}
	return 0;
}
