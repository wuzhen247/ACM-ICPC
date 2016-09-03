//Hdu1255 矩形面积交
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 2005
using namespace std;

struct Line
{
	double x, y1, y2;
	int flag;	
}line[N<<1];

struct Node
{
	int l, r, s;
	double onelen, morelen;
}tree[N<<2];

double y[N<<1];

bool cmp(Line a, Line b)
{
	if (a.x == b.x)
		return a.flag > b.flag;
	return a.x < b.x;
}

void build(int v, int l, int r)
{
	tree[v].l = l;
	tree[v].r = r;
	tree[v].s = 0;
	tree[v].onelen = tree[v].morelen = 0;
	if (l == r - 1)
		return;
	int mid = (l+r) >> 1;
	build(v<<1, l, mid);
	build(v<<1|1, mid, r);
}

void callen(int v)
{
	if (tree[v].s > 1)
	{
		tree[v].onelen = 0;
		tree[v].morelen = y[tree[v].r] - y[tree[v].l];
	}
	else if (tree[v].s == 1)
	{
		if (tree[v].l + 1 == tree[v].r)
			tree[v].morelen = 0;
		else
			tree[v].morelen = tree[v<<1].onelen + tree[v<<1|1].onelen + tree[v<<1].morelen + tree[v<<1|1].morelen;
		tree[v].onelen = y[tree[v].r] - y[tree[v].l] - tree[v].morelen;
	}
	else if (tree[v].s == 0)
	{
		if (tree[v].l + 1 == tree[v].r)
			tree[v].onelen = tree[v].morelen = 0;
		else
		{
			tree[v].morelen = tree[v<<1].morelen + tree[v<<1|1].morelen;
			tree[v].onelen = tree[v<<1].onelen + tree[v<<1|1].onelen;
		}
	}
}

void update(int v, Line u)
{
	if (y[tree[v].l] >= u.y1 && y[tree[v].r] <= u.y2)
	{
		tree[v].s += u.flag;
		callen(v);
		return;
	}
	if (tree[v].l == tree[v].r - 1)
		return;
	int mid = (tree[v].l + tree[v].r)>>1;
	if (u.y1 <= y[mid])
		update(v<<1, u);
	if (u.y2 > y[mid])
		update(v<<1|1, u);
	callen(v);
	return;
}


int main()
{
	int n, num, t, tm;
	double x1, y1, x2, y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		num = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf",&x1, &y1, &x2, &y2);
			line[num].x = x1;
			line[num].y1 = y1;
			line[num].y2 = y2;
			line[num].flag = 1;
			y[num++] = y1;
			line[num].x = x2;
			line[num].y1 = y1;
			line[num].y2 = y2;
			line[num].flag= -1;
			y[num++] = y2;
		}
		sort(line, line+num, cmp);
		sort(y, y+num);
		tm = unique(y, y+num) - y;
		build(1, 0, tm-1);
		double ans = 0;
		update(1,line[0]);
		for (int i = 1; i < num; ++i)
		{
			
			ans += tree[1].morelen * (line[i].x - line[i-1].x);
			update(1, line[i]);
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}