//线段树 单点更新求最大值
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200050
using namespace std;

struct Node
{
	int l,r,g,M;
}tree[N<<2];

void build(int v,int l,int r)
{
	tree[v].l = l;
	tree[v].r = r;
	if(l == r)
	{
		scanf("%d",&tree[v].g);
		tree[v].M=tree[v].g;
		return;
	}
	int mid = (l+r)>>1;
	build(v<<1,l,mid);
	build(v<<1|1,mid+1,r);
	tree[v].M = max(tree[v<<1].M,tree[v<<1|1].M);
}

void update(int v,int p,int m)
{
	if(tree[v].l == tree[v].r)
	{
		tree[v].g = m;
		tree[v].M = m;
		return;
	}
	int mid = (tree[v].l+tree[v].r)>>1;
	if(p<=mid)	update(v<<1,p,m);
	else	update(v<<1|1,p,m);
	tree[v].M = max(tree[v<<1].M,tree[v<<1|1].M);
}

int query(int v,int l,int r)
{
	if(tree[v].l == l && tree[v].r == r)
	{
		return tree[v].M;
	}
	int mid = (tree[v].l + tree[v].r)>>1;
	if(r <= mid)	return query(v<<1,l,r);
	else
	{
		if(l>mid)	return query(v<<1|1,l,r);
		else return max(query(v<<1,l,mid),query(v<<1|1,mid+1,r));
	}
}

int main()
{
	int n,m,a,b;
	char s[10];
	while(scanf("%d%d", &n,&m) !=EOF)
	{
		build(1,1,n);
		while(m--)
		{
			
			scanf("%s", s);
			if(s[0] == 'Q')
			{
				scanf("%d%d",&a,&b);
				printf("%d\n", query(1,a,b));
			}
			else
			{
				scanf("%d%d",&a,&b);
				update(1,a,b);
			}
		}
	}
}
