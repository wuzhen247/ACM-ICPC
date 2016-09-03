//Œª‘ÀÀ„
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool f[4][4];
char s[4][4];
int main()
{
	int i,j,k,ci[16],cj[16],n;
	memset(f,false,sizeof(f));
	for(i=0;i<4;i++)
		gets(s[i]);
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	  {
		  if(s[i][j]=='+')
		  {
			  f[i][j]=!f[i][j];
			  for(k=0;k<4;k++)
			  {
				  f[i][k]=!f[i][k];
				  f[k][j]=!f[k][j];
			  }
		  }
	  }
	n=0;
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
		if(f[i][j])
		{
			ci[n]=i+1;
			cj[n]=j+1;
			n++;
		}
	printf("%d\n",n);
	for(i=0;i<n;i++)
		printf("%d %d\n",ci[i],cj[i]);
	printf("\n");
	return 0;
}
