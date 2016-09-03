#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
unsigned int inf;
int main()
{
	int n,i,j,k,mi,mk,mj;
	while(scanf("%d",&n)!=EOF)
	{
		inf=(unsigned int)(2<<31-1);
		for(i=1;i<=sqrt(n)+1;i++)
		{
			if(n%i==0)
			{
				for(j=1;j<=n/i;j++)
				{
					if(n%(i*j)==0)
					{
					  k=n/(i*j);
					  if(i*j+j*k+i*k<inf)
					  {
						inf=i*j+j*k+i*k;
						mi=i,mj=j,mk=k;
					  }
					}
				}
			}
		}
		printf("%d %d %d\n",mi,mj,mk);
	}
	return 0;
}
