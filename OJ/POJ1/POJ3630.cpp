//×ÖµäÊ÷
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Trie
{
	Trie*next[11];
	bool end;
	void init()
	{
		end=false;
		memset(next,NULL,sizeof(next));
	}
};
Trie node[100010];
int dp;
char str[100];
bool insert(char*str)
{
	Trie*p=&node[0];
	int len=strlen(str),id;
	for(int i=0;i<len;i++)
	{
		id=str[i]-'0';
		if(p->next[id]==NULL)
		{
			p->next[id]=&node[++dp];
			p->next[id]->init();
		}
		p=p->next[id];
		if(p->end) return false;
	}
	p->end=true;
	for(int k=1;k<11;k++)
	  if(p->next[k]!=NULL)
		return false;
	return true;
}

int main()
{
	int t,n;
	bool f;
	scanf("%d",&t);
	while(t--)
	{
		dp=0;
		f=true;
		node[0].init();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",str);
			if(f)
			  f=insert(str);
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
