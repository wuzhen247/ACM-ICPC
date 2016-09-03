#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[1005],i,j,n,max;
	char b[1005][16];
	while(scanf("%d",&n)&&n)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
		  scanf("%s",b[i]);
		  a[i]++;
		}
		for(i=0;i<n-1;i++)
		{
			if(b[i][0]==0)
			  continue;
			for(j=i+1;j<n;j++)
			{
				if(strcmp(b[i],b[j])==0)
				{
					a[i]++;
					memset(b[j],0,sizeof(b[j]));
				}
			}
		}
		max=a[0],j=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				j=i;
			}
		}
		printf("%s\n",b[j]);
	}
	return 0;
}
		

