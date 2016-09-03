#include<iostream>
#include<cstdio>
using namespace std;

struct A
{
	int r,g,b;
}c[16];

int main()
{
	int r,g,b,i,d,temp,id;
	for(i=0;i<16;i++)
	  scanf("%d%d%d",&c[i].r,&c[i].g,&c[i].b);
	while(scanf("%d%d%d",&r,&g,&b))
	{
		if(r==-1&&g==-1&&b==-1)
		  break;
		d=1<<31-1;
		for(i=0;i<16;i++)
		{
			temp=(r-c[i].r)*(r-c[i].r)+(g-c[i].g)*(g-c[i].g)+(b-c[i].b)*(b-c[i].b);
			if(temp<d)
			{
			  d=temp;
			  id=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,c[id].r,c[id].g,c[id].b);
	}
	return 0;
}
