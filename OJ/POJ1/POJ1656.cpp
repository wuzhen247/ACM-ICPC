#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool a[105][105];
int main()
{
	int i,j,t,x,y,l,num;
	char s[10];
	memset(a,0,sizeof(a));
	scanf("%d",&t);
	while(t--)
	{
		num=0;
		scanf("%s%d%d%d",s,&x,&y,&l);
		switch(s[0])
		{
			case 'B':for(i=x;i<x+l;i++)
					   for(j=y;j<y+l;j++)
						 a[i][j]=1;
					 break;
			case 'W':for(i=x;i<x+l;i++)
					   for(j=y;j<y+l;j++)
						 a[i][j]=0;
					 break;
			case 'T':for(i=x;i<x+l;i++)
					   for(j=y;j<y+l;j++)
						 if(a[i][j]==1)
						   num++;
					 printf("%d\n",num);
					 break;
		}
	}
	return 0;
}
