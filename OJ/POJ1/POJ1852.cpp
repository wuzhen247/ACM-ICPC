//蚂蚁 最短 最长时间
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000000
using namespace std;
int main()
{
	int t,i,j,tm,l,n,earliest,longest;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&n);
		earliest=-INF,longest=-INF;
		tm=l/2.0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			if(j<=tm)
			{
				if(j>earliest)
				  earliest=j;
				if(l-j>longest)
				  longest=l-j;
			}
			else
			{
				if(j>longest)
				  longest=j;
				if(l-j>earliest)
				  earliest=l-j;
			}
		}
		printf("%d %d\n",earliest,longest);
	}
	return 0;
}
	
