//´óÊý³Ë·¨
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[45],b[45],c[100];
char s1[45],s2[45];
int main()
{
	int i,j,len1,len2;
	gets(s1);
	gets(s2);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));	
	len1=strlen(s1);
	for(i=len1-1,j=0;i>=0;j++,i--)
	  a[j]=s1[i]-'0';
/*	for(i=len1;i>0;i--)
	  cout<<a[i];*/
	len2=strlen(s2);
	for(i=len2-1,j=0;i>=0;j++,i--)
	  b[j]=s2[i]-'0';
	for(i=0;i<44;i++)
	{
		for(j=0;j<44;j++)
		  c[i+j]+=a[i]*b[j];
	}
	for(i=0;i<100;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	for(i=100;i>=0;i--)
	{
		if(c[i]!=0) 
		  break;
	}
	for(;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
	return 0;
}
