#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[250],b[250];
char s[100];
int n,num,ans;
int main()
{
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		scanf("%s",s);
		j=strlen(s);
		num=ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<j;i++)
		{
			if(a[s[i]]==0)
			{
				if(num<n)
				{
					num++;
					a[s[i]]=1;
				}
				else
				{
					if(b[s[i]]==0)
					{
						ans++;
						b[s[i]]=1;
					}
				}
			}
			else
			{
				a[s[i]]=0;
				num--;
			}
		}
		if(ans)
		  printf("%d customer(s) walked away.\n",ans);
		else
		  printf("All customers tanned successfully.\n");
	}
	return 0;
}
