#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,c,a[25];
bool flag[25],f;

int main()
{
	int max,op,i,sum,count=1;
	while(scanf("%d%d%d",&n,&m,&c)&&(n||m||c))
	{
		memset(flag,false,sizeof(flag));
		printf("Sequence %d\n",count++);
		for(i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		max=sum=0;
		f=false;
		for(i=0;i<m;i++)
		{
			scanf("%d",&op);
			if(flag[op]==false)
			{
				flag[op]=true;
				sum+=a[op];
				{
					if(sum>max)
						max=sum;
				}
			}
			else
			{
				flag[op]=false;
				sum-=a[op];
			}
			if(sum>c)
			  f=true;
		}
		if(f)
		  printf("Fuse was blown.\n\n");
		else
		  printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max);
	}
	return 0;
}
