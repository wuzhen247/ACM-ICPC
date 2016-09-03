/*给出n个高度hei[]，和一个目标高度height，问用这n个高度中的一些相加起来的总高度w大于height，问w-height的最小值是多少。*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[25],minn,n,b;

void dfs(int pos,int sum)
{
	if(sum>=b)	minn=min(sum,minn);
	for(int i=pos;i<=n;i++)
	{
		dfs(i+1,sum+a[i]);
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&b);
	minn=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		minn+=a[i];
	}
	dfs(0,0);
	printf("%d\n",minn-b);
	return 0;
}
