#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=510;
int a[MAX],b[MAX],c[MAX];
char fib[MAX][200];
void add(char ch1[],char ch2[],int n)
{
	int i,j,k,r;
	int len1=strlen(ch1);
	int len2=strlen(ch2);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i=0;i<len1;i++)
	  a[i]=ch1[len1-i-1]-'0';
	for(j=0;j<len2;j++)
	  b[j]=ch2[len2-j-1]-'0';
	for(k=0;k<MAX-5;k++)
	{
	    c[k]+=a[k]+b[k];
		if(c[k]>=10)
		{
			c[k+1]++;
			c[k]-=10;
		}
	}
	i=MAX-5-1;
	while(c[i]==0)
	  i--;
	for(j=0;j<=i;j++)
	  fib[n][j]=c[i-j]+'0';
	fib[n][j]='\0';
}

int main()
{
	int num,i,len_a,len_b,len_i;
	char str1[120],str2[120];
	strcpy(fib[1],"1");
	strcpy(fib[2],"2");
	for(i=3;i<MAX-5;i++)
	  add(fib[i-1],fib[i-2],i);
	while(scanf("%s%s",str1,str2)&&(str1[0]!='0'||str2[0]!='0'))
	{
		num=0;
		len_a=strlen(str1);
		len_b=strlen(str2);
		for(i=1;i<MAX-5;i++)
		{
			len_i=strlen(fib[i]);
			if(len_i>len_b||(len_i==len_b&&strcmp(fib[i],str2)>0))
			  break;
			else if(len_i>len_a||(len_i==len_a&&(strcmp(fib[i],str1)>=0)))
			  num++;
		}
		cout<<num<<endl;
	}
	return 0;
}


