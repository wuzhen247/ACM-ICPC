#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t,i,k,a,b,c,min,max,tmin,tmax;
	int dim[10];
	char na[10][10];
	while(scanf("%d",&t)&&t!=-1)
	{
		for(k=0;k<t;k++)
		{
			scanf("%d%d%d%s",&a,&b,&c,na[k]);
			dim[k]=a*b*c;
		}
		min=dim[0],max=dim[0];
		tmin=tmax=0;
		for(i=1;i<t;i++)
		{
			if(dim[i]>max)
			{
				max=dim[i];
				tmax=i;
			}
			if(dim[i]<min)
			{
				min=dim[i];
				tmin=i;
			}
		}
		printf("%s took clay from %s.\n",na[tmax],na[tmin]);
	}
	return 0;
}
