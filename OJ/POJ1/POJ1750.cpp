#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[100005][15];
int k=1;
int f()
{
	int j;
	for(j=0;s[k][j]&&s[k-1][j];j++)
	 if(s[k][j]!=s[k-1][j])
		return j;
	return j;
}

int main()
{
	int i,a,n=0;
	while(scanf("%s",&s[k])!=EOF)
	{
		a=f();
		if(a>n) ++n;
		else    n=a;
		for(i=0;i<n;i++)
		  printf(" ");
		printf("%s\n",s[k++]);
	}
	return 0;
}
