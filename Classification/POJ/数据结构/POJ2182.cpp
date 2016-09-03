//Lost Cows 由逆序数得到原序
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 8005
using namespace std;

int t[N],ans[N];

struct Node
{
	int l,r,len;
}tree[N<<2];

void build(int v,int l,int r)
{
	tree[v].l = l;
	tree[v].r = r;
	tree[v].len = r-l+1;
	if(l == r)	return;
	int mid = (l+r)>>1;
	build(v<<1,l,mid);
	build(v<<1|1,mid+1,r);
}

int query(int v,int k)
{
	tree[v].len--;
	if(tree[v].l == tree[v].r)	return tree[v].l;
	if(k <= tree[v<<1].len)	return query(v<<1,k);
	else return query(v<<1|1,k-tree[v<<1].len);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i = 2; i <=n; ++i)
		scanf("%d" ,&t[i]);
	t[1]=0;
	build(1,1,n);
	for(i = n;i > 0;i--)
		ans[i] = query(1,t[i]+1);
	for(i = 1;i<=n;i++)
		printf("%d\n", ans[i]);
	return 0;
}