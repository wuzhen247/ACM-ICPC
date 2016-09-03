//POJ2259 Team Queue 数据结构 单向队列
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int t,n,nM[1000000];
queue<int>nQue[1005];
queue<int>nS;
bool f[1005];

void init()
{
	for(int i=0;i<n;i++)
	{
		f[i]=false;
		while(!nQue[i].empty())
		  nQue[i].pop();
	}
	while(!nS.empty())	nS.pop();
}

void input()
{
	int nElem,eleNum;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&eleNum);
		for(int j=0;j<eleNum;j++)
		{
			scanf("%d",&nElem);
			nM[nElem]=i;
		}
	}
}

void solve()
{
	char order[20];
	int nElem;
	printf("Scenario #%d\n",++t);
	while(scanf("%s ",order)&&strcmp(order,"STOP"))
	{
		if(!strcmp(order,"ENQUEUE"))
		{
			scanf("%d",&nElem);
			if(!f[nM[nElem]])
			{
				 f[nM[nElem]]=true;
				 nS.push(nM[nElem]);
			}
			nQue[nM[nElem]].push(nElem);
		}
		else
		{
			int at=nS.front();
			printf("%d\n",nQue[at].front());
			nQue[at].pop();
			if(nQue[at].empty())
			{
				nS.pop();
				f[at]=false;
			}
		}
	}
	printf("\n");
}
			
int main()
{
	t=0;
	while(scanf("%d",&n),n)
	{
		init();
		input();
		solve();
	}
	return 0;
}
