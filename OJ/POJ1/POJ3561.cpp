//判断是否是图形是否是一条线段
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s[15][15];
int t,n,m;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(s,'.',sizeof(s));
		int i,j,ans=0;
		for(i=1;i<=n;i++)
		{
		  for(j=1;j<=m;j++)
		  {
			  //scanf("%c",&s[i][j]);
			  cin>>s[i][j];
			  if(s[i][j]!='.')
			  {
				  switch(s[i][j])
				  {
					  case '-': if(s[i][j-1]=='-'||s[i][j+1]=='-')	break;
								else{	ans++;break;}
					  case '|': if(s[i-1][j]=='|'||s[i+1][j]=='|')	break;
								else{	ans++;break;}
					  case '/': if(s[i-1][j+1]=='/'||s[i+1][j-1]=='/')	break;
								else{	ans++;break;}
					  case '\\': if(s[i-1][j-1]=='\\'||s[i+1][j+1]=='\\')	break;
								else{	ans++;break;}
				  }
			  }
		  }
		}
		if(ans==1)	printf("CORRECT\n");
		else	printf("INCORRECT\n");
	}
	return 0;
}
