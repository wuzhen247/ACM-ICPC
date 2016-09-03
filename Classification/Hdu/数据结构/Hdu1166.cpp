//线段树 单点加减，区间求和
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 50005
using namespace std;

struct Node
{
	int l,r;
	int sum;	
}tree[N<<2];


void build(int v,int l,int r)
{
	tree[v].l = l;
	tree[v].r = r;
	if(l==r)
	{
		scanf("%d", &tree[v].sum);
		return;
	}
	int mid = (l+r)>>1;
	build(v<<1,l,mid);
	build((v<<1)|1,mid+1,r);
	tree[v].sum = tree[v<<1].sum + tree[(v<<1)|1].sum;
}

void update(int v,int p,int add)
{
	if(tree[v].l == tree[v].r)
	{
		tree[v].sum += add;
		return;
	}
	int mid = (tree[v].l + tree[v].r)>>1;
	if(p<=mid)	update(v<<1,p,add);
	else update(v<<1|1,p,add);
	tree[v].sum = tree[v<<1].sum + tree[v<<1|1].sum;
}

int query(int v,int l,int r)
{
	if(tree[v].l == l && tree[v].r == r)
	{
		return tree[v].sum;
	}
	int mid = (tree[v].l + tree[v].r)>>1;
	if(r <= mid)	return query(v<<1,l,r);
	else
	{
		if(l>mid)	return query((v<<1)|1,l,r);
		else return query(v<<1,l,mid) + query((v<<1)|1,mid+1,r);
	}
}

int main()
{
	int t,n,a,b;
	char op[10];
	scanf("%d",&t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case %d:\n", i);
		scanf("%d", &n);
		build(1,1,n);

		while(scanf("%s", op) && op[0] != 'E')
		{
			scanf("%d%d", &a,&b);
			if(op[0] == 'Q')	printf("%d\n", query(1,a,b));
			else if(op[0] == 'A')	update(1,a,b);
			else update(1,a,-b);
		}
	}
}