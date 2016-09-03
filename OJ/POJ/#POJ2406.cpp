#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
int next[N];
void get_next(char*t)
{
	int p=0,l=0,n=-1;
	p=strlen(t);
	next[0]=-1;
	for(l=0;l<p;l++)
	{
		while(n>=0&&t[n]!=t[l])
		{
			n=next[n];
		}
		if(n<0||t[n]==t[l])
		{
			n++;
			next[l+1]=n;
		}
	}
}
int main()
{
	char s[1000010];
	int i=0,n,ns;
	while(scanf("%s",s))
	{
		ns=strlen(s);
		if(s[0]=='.')
			break;
		get_next(s);
		if(ns%(ns-next[ns])==0)
		{
			n=ns/(ns-next[ns]);
			printf("%d\n",n);
		}
		else
			printf("%d\n",1);
	}
	return 0;
}
