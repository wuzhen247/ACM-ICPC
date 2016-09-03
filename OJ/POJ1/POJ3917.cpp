#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100],b[100];
	int n,i,s1,s2;
	while(scanf("%s%s",a,b))
	{
		if(a[0]=='E'&&b[0]=='E')
		  break;
		s1=s2=0;
		n=strlen(a);
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
			  continue;
			switch(a[i])
			{
				case 'R':if(b[i]=='S') s1++;
						 else s2++;break;
				case 'P':if(b[i]=='R') s1++;
						 else s2++;break;
				case 'S':if(b[i]=='P') s1++;
						 else s2++;break;
			}
		}
		printf("P1: %d\nP2: %d\n",s1,s2);
	}
	return 0;
}
