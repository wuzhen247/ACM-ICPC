#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1010],b[1010];
int main()
{
	int i,n,j;
	char c;
	while(gets(b)!=NULL)
	{
		n=strlen(b);
		i=0;
		for(j=0;j<n;j++)
		{
			switch(b[j])
			{
				case '(':
				case '{':
				case '[':;a[++i]=b[j];break;
				case ')':if(a[i]=='(') i--;
						else a[++i]=c;break;
				case ']':if(a[i]=='[') i--;
						else a[++i]=c;break;
				case '}':if(a[i]=='{') i--;
						else a[++i]=c;break;
			}
		}
	
		if(i==0)
				printf("Yes\n");
			else
				printf("No\n");
	}
	return 0;
}

