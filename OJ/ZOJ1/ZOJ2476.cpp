#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,k,n,b[20],len;
	char s[20];
	while(scanf("%d",&n)&&n)
	{
		memset(b,0,sizeof(b));
		for(k=0;k<n;k++)
		{
		  scanf("%s",s);
		  len=strlen(s);
		  for(i=len-1,j=0;i>0;i--)
		  {
			  if(s[i]=='.'||s[i]==',')
				continue;
			  b[j]+=s[i]-'0';
			  j++;
		  }
		}
		for(i=0;i<19;i++)
		{
			b[i+1]+=b[i]/10;
			b[i]%=10;
		}
		printf("$");
		for(j=19;j>=0;j--)
		  if(b[j]!=0)
			break;
		if(j<=2)
		{
			printf("%d.%d%d\n",b[2],b[1],b[0]);
		}
		else
		{
			for(;j>2;j--)
			{
				if(j%3==2)
				  printf("%d,",b[j]);
				else
				  printf("%d",b[j]);
			}
			printf("%d.%d%d\n",b[2],b[1],b[0]);
		}	
	}
	return 0;
}


