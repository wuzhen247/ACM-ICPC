//统计字符，普通字符不计重复，空格不计
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s[7][5]={"ffi","ffl","fi","fl","ff","``","\'\'"};
bool f[128];
char tm[150];

int main()
{
	memset(f,false,sizeof(f));
	f[' ']=true;
	int ans=0;
	while(gets(tm))
	{
		int n,i;
		for(i=0;i<strlen(tm);)
		{
			for(n=0;n<7;n++)
			  if(strncmp(s[n],tm+i,strlen(s[n]))==0)
				break;
			if(n<7)	i+=strlen(s[n]);
			else
			{
				n=tm[i];
				i++;
			}
			if(!f[n])
			{
				f[n]=true;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
