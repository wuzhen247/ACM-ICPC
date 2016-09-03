#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[10];
int main()
{
	int t,j,len;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		len=strlen(s);
		if(len==1)
		{
			printf("%c\n",s[0]);
			continue;
		}
		for(j=len-1;j>0;j--)
		{
			if(s[j]==':')
			{
				s[j]='0';
				s[j-1]++;
				continue;
			}
			if(s[j]>'4')
			  s[j-1]++;
			s[j]='0';
		}
		if(s[0]==':')
		{
			s[0]='0';
			printf("1");
		}
		printf("%s\n",s);
	}
	return 0;
}

