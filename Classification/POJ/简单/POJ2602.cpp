#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[1000005];

int main()
{
	int n,i,x,y;
	memset(s,0,sizeof(s));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		s[i]=x+y+'0';
	}
	for(i=n;i>=1;i--)
	{
		s[i-1]+=(s[i]-'0')/10;
		s[i]=(s[i]-'0')%10+'0';
	}
	printf("%s\n", s+1);
	return 0;
}