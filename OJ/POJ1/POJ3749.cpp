#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[110];
int main()
{
	int len,i;
	while(1)
	{
		gets(s);
		if(strcmp(s,"ENDOFINPUT")==0)
		  break;
		if(strcmp(s,"START")==0||strcmp(s,"END")==0)
		  continue;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
			  s[i]-=5;
				if(s[i]<'A')
				  s[i]+=26;
			}
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
