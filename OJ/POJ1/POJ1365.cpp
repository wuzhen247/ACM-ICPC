// sum=(x1^n1)*(x2^n2)......(xn^nn) 求sum-1的因式分解
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 35000
using namespace std;
struct A
{
	int a,b;
}re[1000];
int prime[N],nprime,sum,temp1,temp2;
bool vis[N];
char s[1000];
char*str;
void pri()
{
	int i,j;
	nprime=0;
	memset(vis,true,sizeof(vis));
	vis[1]=false;
	for(i=2;i<N;i++)
	{
		if(vis[i])
		{
			prime[++nprime]=i;
			for(j=i*i;j<N;j+=i)
				vis[j]=false;
		}
	}
}

int main()
{
	int num,i,j;
	pri();
	while(gets(s)&&s[0]!='0')
	{
		sum=1;
		str=strtok(s," ");
		sscanf(str,"%d",&temp1);
		str=strtok(NULL," ");
		sscanf(str,"%d",&temp2);
		for(j=0;j<temp2;j++)
			sum*=temp1;
		while(1)
		{
			str=strtok(NULL," ");
			if(str==NULL) break;
			sscanf(str,"%d",&temp1);
			str=strtok(NULL," ");
			sscanf(str,"%d",&temp2);
			for(j=0;j<temp2;j++)
				sum*=temp1;
		}
		sum--;
		num=0;
		i=1;
		memset(re,0,sizeof(re));
		while(sum!=1)
		{
			if(sum%prime[i]==0)
			{
				re[num].a=prime[i];
				re[num].b=1;
				sum/=prime[i];
				while(sum%prime[i]==0)
				{
					re[num].b++;
					sum/=prime[i];
				}
				num++;
			}
			else
			    i++;			
		}
		j=num-1;
		cout<<re[j].a<<' '<<re[j].b;
		j--;
		while(j>=0)
		{
			cout<<' '<<re[j].a<<' '<<re[j].b;
			j--;
		}
		cout<<endl;
	}
	return 0;
}
