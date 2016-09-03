//ip address
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,tm,i,j,k;
	char s[35];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(s);
		for(j=7;j<=31;j+=8)
		{
			k=1,tm=0;
			for(i=j;i>j-8;i--)
			{
				if(s[i]=='1')
				  tm+=k;
				k<<=1;
			}
			printf("%d",tm);
			if(j!=31)
			  printf(".");
		}
		printf("\n");
	}
	return 0;
}
		
