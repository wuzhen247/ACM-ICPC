#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,j,a[13],num,max;
	char s[13][25];
	while(scanf("%d",&n)&&n)
	{
		getchar();
		max=-1,num=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			gets(s[i]);
			for(j=0;j<25;j++)
			{
				if(s[i][j]=='X')
				  a[i]++;
			}
			if(a[i]>max)
			  max=a[i];
		}
		for(i=0;i<n;i++)
		  num+=max-a[i];
		printf("%d\n",num);
	}
	return 0;
}
