#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 20005
using namespace std;
int a[N],dis[N];
int t,n;
int getfather(int x)
{
	if(a[x]==x)
	  return x;
	else
	{
		getfather(a[x]);
		dis[x]+=dis[a[x]];
		a[x]=getfather(a[x]);
		return a[x];
	}
}
int main()
{
	int i,j,k,temp;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(dis,0,sizeof(dis));
		for(k=1;k<=n;k++)
		  a[k]=k;
		while(cin>>ch&&ch!='O')
		{
			if(ch=='E')
			{
				scanf("%d",&i);
				getfather(i);
				printf("%d\n",dis[i]);
			}
			else
			{
				scanf("%d%d",&i,&j);
				a[i]=j;
				temp=abs(i-j);
				dis[i]=temp%1000;
			}
		}
	}
	return 0;
}
