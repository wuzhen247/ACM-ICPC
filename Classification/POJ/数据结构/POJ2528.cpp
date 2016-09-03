//POJ2528 贴海报 线段树+离散化
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 20050
using namespace std;

struct Node
{
	int l,r;
	bool vis;
}tree[N<<2];

struct Data
{
	int pos;
	int id;
}post[N];

bool flag;

bool cmp1(Data a,Data b)
{
	return a.pos < b.pos;
}

bool cmp2(Data a,Data b)
{
	if(a.id == b.id)
		return a.pos < b.pos;
	return a.id > b.id;
}

void Build(int v,int l,int r)
{
	tree[v].l = l;
	tree[v].r = r;
	tree[v].vis = false;
	if(l == r)
		return;
	int mid = (l+r)>>1;
	Build(v<<1,l,mid);
	Build(v<<1|1,mid+1,r);
}

void query(int v,int l,int r)
{
	if(tree[v].vis) return;
	if(tree[v].l == l && tree[v].r == r)
	{
		tree[v].vis = true;
		flag = true;
		return;
	}
	int mid = (tree[v].l+tree[v].r)>>1;
	if(r <= mid)
		query(v<<1,l,r);
	else if(l > mid)
		query(v<<1|1,l,r);
	else
	{
		query(v<<1,l,mid);
		query(v<<1|1,mid+1,r);
	}
	tree[v].vis = tree[v<<1].vis && tree[v<<1|1].vis;
} 

int main()
{
	int t,n,k,pre,i,l,r,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			scanf("%d%d",&post[i<<1].pos,&post[i<<1|1].pos);
			post[i<<1].id = post[i<<1|1].id = i;
		}
		sort(post,post + 2*n,cmp1);
		k = pre = 0;
		for(i = 0; i < 2*n; i++)
		{
			if(post[i].pos != pre)
			{
				pre = post[i].pos;
				post[i].pos = ++k;
			}
			post[i].pos = k;
		}
		Build(1,1,k);
		sort(post,post + 2*n,cmp2);
		for(i = 0; i < n; i++)
		{
			l = post[i<<1].pos;
			r = post[i<<1|1].pos;
			flag = false;
			query(1,l,r);
			if(flag)
				ans++;
		}
		printf("%d\n", ans);
	}
}