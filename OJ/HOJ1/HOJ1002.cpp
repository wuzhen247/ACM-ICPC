#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t,i,j,k,c[1005],d[1005],tm1,tm2;
	char a[1005],b[1005];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%s %s",a,b);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		tm1=strlen(a);
		for(i=tm1-1,j=0;i>=0;i--,j++)
		  c[j]=a[i]-48;

		tm2=strlen(b);
		for(i=tm2-1,j=0;i>=0;i--,j++)
		  d[j]=b[i]-48;

		for(i=0;i<1005;i++)
		  d[i]=c[i]+d[i];
		for(i=0;i<1005;i++)
		{
			if(d[i]>9)
			{
				d[i+1]+=d[i]/10;
				d[i]%=10;
			}
		}
		printf("Case %d:\n%s + %s = ",k,a,b);
		for(j=1004;j>=0;j--)
		if(d[j]!=0)	break;
		for(i=j;i>=0;i--)
		  printf("%d",d[i]);
		if(k<t)
			printf("\n\n");
		else
			printf("\n");
	}
	return 0;
}
