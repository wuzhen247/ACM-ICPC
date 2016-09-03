//×ÖµäÊ÷ 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Trie
{
	Trie*next[2];
	bool end;
	void init()
	{
		end=false;
		memset(next,NULL,sizeof(next));
	}
};

Trie node[10000];
int id;
char str[100];
bool insert(char*str)
{
	int len=strlen(str),j;
	Trie*p=&node[0];
	for(int i=0;i<len;i++)
	{
		j=str[i]-'0';
		if(p->next[j]==NULL)
		{
			p->next[j]=&node[++id];
			p->next[j]->init();
		}
		p=p->next[j];
		if(p->end) return false;
	}
	if(p->next[0]!=NULL||p->next[1]!=NULL)
	  return false;
	p->end=true;
	return true;
}

int main()
{
	int t=0;
	while(scanf("%s",str)!=EOF)
	{
		node[0].init();
		id=0;
		insert(str);
		bool f=true;
		while(scanf("%s",str))
		{
			if(str[0]=='9')
			  break;
			if(f==true)
			  f=insert(str);
		}
		if(f==true)
			printf("Set %d is immediately decodable\n",++t);
		else
		    printf("Set %d is not immediately decodable\n",++t);
	}
	return 0;
}

