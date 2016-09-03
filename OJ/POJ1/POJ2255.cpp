//tree recovery 树的遍历
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char p[50],m[50];

int dfs(int f,int b,int e)
{
	int i,j;
	for(i = b;i <= e && m[i] != p[f]; i++);
	if( i!=b )
		f=dfs(f+1, b,i-1);
	if( i!=e )
		f=dfs(f+1,i+1,e);
	printf("%c", m[i]);
	return f;
}

int main()
{
	while(scanf("%s %s",p,m) != EOF)
	{
		dfs(0,0,strlen(m)-1);
		printf("\n");
	}
	return 0;
}