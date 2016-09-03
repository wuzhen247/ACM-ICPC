//music 随机播放算法
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int r[10005];
int n,t;

int main()
{
	int i,j,max,index,div,mod;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
		scanf("%d",&r[i]);
	while(t--)
	{
		max=-1;
		for(i=1;i<=n;i++)
		{
			if(r[i]>max)
			{
				max=r[i];
				index=i;
			}
		}
		printf("%d\n", index);
		div=r[index]/(n-1);
		mod=r[index]%(n-1);
		for(i=1;i<=n;i++)
		{
			if(i!=index)
				r[i]+=div;
		}
		for(i=1;i<=n&&mod;i++)
		{
			if(i!=index)
			{
				r[i]++;
				mod--;
			}
		}
		r[index]=0;
	}
	return 0;
}