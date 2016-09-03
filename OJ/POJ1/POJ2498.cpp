#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t,sum,i,j,k,len,temp,index;
	int a[3]={9,3,7};
	char ch[9];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%s",ch);
		len=strlen(ch);
		for(i=len-1,j=0,sum=0;i>=0;i--)
		{
			if(ch[i]=='?')
			{
				temp=a[j++];
				index=i;
			}
			else
			{
				sum+=(ch[i]-'0')*a[j++];
			}
			if(j==3) j=0;
		}
		for(i=0;i<10;i++)
		  if((sum+temp*i)%10==0)
		  {
			ch[index]=char(i+'0');
			break;
		  }
		printf("Scenario #%d:\n%s\n\n",k,ch);
	}
	return 0;
}
