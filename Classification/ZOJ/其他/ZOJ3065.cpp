//给你一本n个单词的字典，再给你几块字母砖，空格的砖则可当做任意的字母使用，问这几块字//母砖最多能拼成字典里面的几个单词？
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char s[1005][8],tile[8];
bool vis[8];
int n;

int main()
{
	int ans,i,j,k,blank,st,len,num;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		  scanf("%s",s[i]);
		scanf("%s",tile);
		st=strlen(tile);
		for(i=0,blank=0;i<st;i++)
		  if(tile[i]=='_')	blank++;
		ans=0;
		for(i=0;i<n;i++)
		{
			len=strlen(s[i]);
			num=0;
			memset(vis,false,sizeof(vis));
			for(j=0;j<len;j++)
			{
				for(k=0;k<st;k++)
				  if(!vis[k]&&s[i][j]==tile[k])
				  {
					  vis[k]=true;
					  num++;
					  break;
				  }
			}
			if(num+blank>=len)	ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
