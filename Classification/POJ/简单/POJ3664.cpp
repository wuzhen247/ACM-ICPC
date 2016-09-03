//二轮选举
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Un
{
	int index;
	int a;
	int b;
};

Un r[50005];

bool cmp1(Un l, Un r)
{
	return l.a>r.a;
}
bool cmp2(Un l,Un r)
{
	return l.b>r.b;
}

int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		r[i].index=i;
		scanf("%d%d",&r[i].a,&r[i].b);
	}
	sort(r,r+n,cmp1);
	sort(r,r+k,cmp2);
	printf("%d\n", r[0].index+1);
	return 0;
}