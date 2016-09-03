#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char a[20],b[20],c[250];
	int i,j,len;
	while(scanf("%s",a))
	{
		if(strcmp(a,"ENDOFINPUT")==0)
		  break;
		getchar();
		gets(c);
		len=strlen(c);
		for(i=0;i<len;i++)
		{
			if(c[i]>='A'&&c[i]<='Z')
			{
				c[i]=char(c[i]-5);
				if(c[i]<'A')
				  c[i]=char(c[i]+'Z'-'A'+1);
			}
		}
		puts(c);
		scanf("%s",b);
		getchar();
	}
	return 0;
}
