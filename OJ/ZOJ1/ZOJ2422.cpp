//与POJ2082相同，方法不同，此题暴力
#include<iostream>
#include<cstdio>
using namespace std;

struct rec
{
	int w,h;
}data[50005];

bool cmp(rec a,rec b)
{
	return a.h<b.h;
}

int main()
{
	int n,ans,totalw,area,i,j;
	while(scanf("%d",&n)&&n!=-1)
	{
		for(i=0;i<n;i++)
		  scanf("%d%d",&data[i].w,&data[i].h);
		totalw=0,ans=0;
		for(i=0;i<n;i++)
		{
			totalw=data[i].w;
			for(j=i-1;j>=0;j--)
			{
				if(data[j].h<data[i].h)
				  break;
				totalw+=data[j].w;
			}
			for(j=i+1;j<n;j++)
			{
				if(data[j].h<data[i].h)
				  break;
				totalw+=data[j].w;
			}
			area=data[i].h*totalw;
			if(area>ans)
			  ans=area;
		}
		printf("%d\n",ans);
	}
	return 0;
}

