#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	int n,p,i,j,a[105][105],ans[105];
	int s=0,hard;
	bool f;
	scanf("%d%d",&n,&p);
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++)
	  for(j=1;j<=p;j++)
		scanf("%d",&a[i][j]);
	f=true;
	for(i=1;i<=n;i++)
	{
		s=1000000000,hard=-1;
		for(j=1;j<=p;j++)
		{
			if(a[i][j]<s)
			  s=a[i][j];
			if(a[i][j]>hard)
			  hard=a[i][j];
		}
		for(j=1;j<=p;j++)
		{
			if(a[i][j]==hard)
			  ans[j]=-1;
		    if(a[i][j]==s&&ans[j]!=-1)
				ans[j]++;
		}
	}
	for(j=1;j<=p;j++)
	{
		if(ans[j]>n/2)
		{
		  printf("%d",j);
		  f=false;
		  if(j!=p)
			printf(" ");
		}
	}
	if(f) printf("0");
	printf("\n");
	return 0;
}
		

