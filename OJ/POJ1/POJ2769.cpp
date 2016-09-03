#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool b[10000001],flag;
int t,n,a[305],c[1000000],n1,i,j;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		for(i=1;;i++)
		{
			n1=0;
			flag=false;
			for(j=0;j<n;j++)
			{
				c[++n1]=a[j]%i;
				if(b[c[n1]])
				{
					flag=true;
					break;
				}
				b[c[n1]]=true;
			}
			if(flag==false)
			  break;
			for(j=1;j<=n1;j++)
				b[c[j]]=0;
		}
		printf("%d\n",i);
	}
	return 0;
}
		


