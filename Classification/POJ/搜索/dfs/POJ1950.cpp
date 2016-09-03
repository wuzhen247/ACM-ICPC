//1 - 2 . 3 - 4 . 5 + 6 . 7
#include<iostream>
#include<cstdio>
using namespace std;

int ans,n;
char a[20];
bool f;

bool dfs(int id,int front,int tm)
{
	if(id==n)
	{
		if(tm==0)
		{
			ans++;
			if(ans<=20)
			{
				printf("1");
				for(int i=2;i<=id;i++)
				{
					printf(" %c %d",a[i-1],i);
				}
				printf("\n");
			}
			return true;
		}
		else return false;
	}
	a[id]='+';
	if(dfs(id+1,id+1,tm+(id+1)))	f=true;

	a[id]='-';
	if(dfs(id+1,id+1,tm-(id+1)))	f=true;

	a[id]='.';
	int j=id,now,k;
	while(a[j]=='.'&&j>0)	j--;
	if(id>=9)
		now=front*100+id+1;
	else
		now=front*10+id+1;
	if(j<1)		k=now;
	else if(a[j]=='-')	k=tm+front-now;
	else k=tm-front+now;
	if(dfs(id+1,now,k))	f=true;
	if(f)	return true;
	else 	return false;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		f=false;
		ans=0;
		dfs(1,1,1);
		printf("%d\n", ans);
	}
	return 0;
}
