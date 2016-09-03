//是否是同一伙黑社会
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100050
using namespace std;
int father[N];
bool dis[N];
int getfather(int x)
{
	if(father[x]==x)
	  return x;
	else
	{
		int temp=getfather(father[x]);
		dis[x]^=dis[father[x]];
		return father[x]=temp;
	}
}
void add(int x,int y)
{
	int fx=getfather(x);
	int fy=getfather(y);
	if(fx!=fy)
	{
	  dis[fx]=1^dis[x]^dis[y];
	  father[fx]=fy;
	}
}
bool same(int x,int y)
{
	return getfather(x)==getfather(y);
}
int main()
{
	int t,i,j,k,n,m,a,b;
	char ch;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		  father[i]=i;
		memset(dis,0,sizeof(dis));
		for(j=0;j<m;j++)
		{
			cin>>ch;
			scanf("%d%d",&a,&b);
			switch(ch)
			{
				case 'A':if(same(a,b)&&dis[a]==dis[b])
						   printf("In the same gang.\n");
						 else if(same(a,b)&&dis[a]!=dis[b])
							printf("In different gangs.\n");						
						 else
						   printf("Not sure yet.\n");
						 break;
				case 'D':add(a,b);break;
			}
		}
	}
	return 0;
}
