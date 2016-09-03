//基本堆操作
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

struct Node
{
	int id;
	int t;
	int cur;
};

Node H[3005];
int len,n;

void down(Node H[],int s,int len)
{
	Node tm=H[s];
	int i;
	for(i=2*s;i<=len;i*=2)
	{
		if(i<len)
		{
			if(H[i].cur>H[i+1].cur)
				i++;
			else if(H[i].cur==H[i+1].cur && H[i].id>H[i+1].id)
				i++;
		}
		if(tm.cur<H[i].cur || (tm.cur==H[i].cur && tm.id<H[i].id))
			break;
		H[s]=H[i];
		s=i;
	}
	H[s]=tm;
}

void Built(Node H[],int len)
{
	for(int i=len/2;i>0;i--)
		down(H,i,len);
}

int main()
{
	len=0;
	string s;
	cin>>s;
	while(s.compare("#")!=0)
	{
		len++;
		scanf("%d%d",&H[len].id,&H[len].t);
		H[len].cur=H[len].t;
		cin>>s;
	}
	Built(H,len);
	scanf("%d",&n);
	while(n--)
	{
		printf("%d\n", H[1].id);
		H[1].cur+=H[1].t;
		down(H,1,len);
	}
	return 0;
}