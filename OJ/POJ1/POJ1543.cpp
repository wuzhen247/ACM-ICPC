#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int p[103];
int main()
{
	int n,i,j,k,t;
	for(i=1;i<102;i++)
	  p[i]=i*i*i;
	scanf("%d",&n);
	for(i=6;i<=n;i++)
	{
		for(j=2;j<n;j++)
		{
			for(k=j;k<n;k++)
			{
				for(t=k;t<n;t++)
				if(p[i]==p[j]+p[k]+p[t])
				{
					printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,t);
					break;
				}
			}
		}
	}
	return 0;
}
	
