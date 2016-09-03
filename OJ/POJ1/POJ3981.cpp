#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[1005];
	int i,j,len;
	while(gets(s)!=NULL)
	{
		len=strlen(s);
		j=len-2;
		for(i=0;i<j;i++)
		{
			if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u')
			{
				s[i]='w',s[i+1]='e',s[i+2]='\n';
			}
		}
		for(i=0;i<len;i++)
		{
			if(s[i]!='\n')
			  printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
