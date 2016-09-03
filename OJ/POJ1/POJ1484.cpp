#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int a[25],n,m,c,i,j=0,max,id,temp;
	bool b[50],f;
	while(scanf("%d%d%d",&n,&m,&c)&&(n||m||c))
	{
		memset(b,0,sizeof(b));
		max=temp=0,f=false;
		for(i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		for(i=0;i<m;i++)
		{
			scanf("%d",&id);
			if(f==true)
			  continue;
			if(b[id]==0)
			{
				b[id]=1;
				temp+=a[id];
			}
			else
			{
				b[id]=0;
				temp-=a[id];
			}
			if(temp>c)
			  f=true;
			if(temp>max)
			  max=temp;
		}
		j++;
		printf("Sequence %d\n",j);
		if(f==true)
		  printf("Fuse was blown.\n\n");
		else
		  printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",
					  max);
	}
	return 0;
}
