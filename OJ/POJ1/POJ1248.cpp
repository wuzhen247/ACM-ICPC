//dfs
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool vis[20];
int per[30][7],num[7],ans[7],len,sum;
char ch[20];
bool f;
void pow()
{
	int i,j;
	for(i=1;i<=26;i++)
	{
		per[i][0]=1;
		for(j=1;j<=5;j++)
		  per[i][j]=per[i][j-1]*i;
	}
}
bool cmp()
{
	int i=0;
	for(i=0;i<5;i++)
	{
		if(num[i]>ans[i]) return true;
		if(num[i]<ans[i]) return false;
	}
}
void dfs(int k)
{
	if(k==5)
	{
		int tm=per[num[0]][1]-per[num[1]][2]+per[num[2]][3]-per[num[3]][4]+per[num[4]][5];
		if(tm==sum&&cmp())
		{
			for(int i=0;i<5;i++)
			  ans[i]=num[i];
			f=true;
		}
		return;
	}
	for(int i=0;i<len;i++)
	{
		if(!vis[i])
		{
			num[k]=ch[i]-'A'+1;
			vis[i]=true;
			dfs(k+1);
			vis[i]=false;
		}
	}
}

int main()
{
	int i,j;
	pow();
	while(scanf("%d %s",&sum,&ch))
	{
		if(sum==0&&strcmp(ch,"END")==0)
		  break;
		f=false;
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		len=strlen(ch);
		dfs(0);
		if(f)
		{
			for(i=0;i<5;i++)
			  printf("%c",char(ans[i]+'A'-1));
		}
		else
		  printf("no solution");
		printf("\n");
	}
	return 0;
}
