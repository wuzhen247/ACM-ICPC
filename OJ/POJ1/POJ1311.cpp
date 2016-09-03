//高精度小数八进制转十进制
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100];
char ch[100];
int main()
{
	int len,i,j,k,pos,s;
	while(scanf("%s",&ch)!=EOF)
	{
		len=strlen(ch);
		pos=0;
		memset(a,0,sizeof(a));
		for(i=len-1;i>=2;i--)
		{
			j=s=0;
			a[0]=ch[i]-'0';
			while(j<=pos||s!=0)
			{
				s=s*10+a[j];
				a[j]=s/8;
				s%=8;
				j++;
			}
			pos=j-1;
		}
		printf("%s [8] = 0.",ch);
		for(k=1;k<=pos;k++)
		  printf("%d",a[k]);
		printf(" [10]\n");
	}
	return 0;
}
