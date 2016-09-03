//求四格点平均值，向下取整
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10][10];
char b[10][10];
int main()
{
	int i,j,r,c,ave;
	char tm[10];
	while(scanf("%s",tm),strcmp(tm,"ENDOFINPUT"))
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&r,&c);
		getchar();
		for(i=0;i<r;i++)
		  gets(b[i]);
		for(i=0;i<r;i++)
		  for(j=0;j<c;j++)
			a[i][j]=b[i][j]-'0';
		for(i=1;i<r;i++)
		{
			for(j=1;j<c;j++)
			{
			  ave=a[i][j]+a[i-1][j-1]+a[i][j-1]+a[i-1][j];
			  printf("%d",ave/4);
			}
			printf("\n");
		}
		gets(tm);
	}
	return 0;
}
			
