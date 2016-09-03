//矩形面积并
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 305
using namespace std;

struct Line
{
	double x, y1, y2;
	int flag;
}line[N<<1];

struct Node
{
	int l, r, s;
	double ml, mr, len;
}tree[N<<2];

double y[N<<1];

bool cmp(Line a, Line b)
{
	return a.x < b.x;
}

void build(int v, int l, int r)
{
	tree[v].l = l;
	tree[v].r = r;
	tree[v].ml = y[l];
	tree[v].mr = y[r];
	tree[v].s = 0;
	tree[v].len = 0;
	if (l + 1 == r)
		return;
	int mid = (l+r)>>1;
	build(v<<1, l, mid);
	build(v<<1|1, mid, r);
}

void callen(int i)
{
	if(tree[i].s>0)
		tree[i].len = tree[i].mr - tree[i].ml;
	else if(tree[i].l + 1 == tree[i].r)
		tree[i].len = 0;
	else 
		tree[i].len = tree[i<<1].len + tree[i<<1|1].len;
	return; 
}

void update(int v, Line u)
{
	if (tree[v].ml == u.y1 && tree[v].mr == u.y2)
	{
		tree[v].s += u.flag;
		callen(v);
		return;
	}
	if (u.y2 <= tree[v<<1].mr)	update(v<<1,u);
	else if (u.y1 >= tree[v<<1|1].ml)	update(v<<1|1,u);
	else
	{
		Line tm = u;
		tm.y2 = tree[v<<1].mr;
		update(v<<1,tm);
		tm = u;
		tm.y1 = tree[v<<1|1].ml;
		update(v<<1|1,tm);
	}
	callen(v);
	return;
}

int main()
{
	int n, num, Case = 1;
	double x1, y1, x2, y2;
	while(scanf("%d",&n), n)
	{
		num = 1;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			line[num].x = x1;
			line[num].y1 = y1;
			line[num].y2 = y2;
			line[num].flag = 1;
			y[num++] = y1;
			line[num].x = x2;
			line[num].y1 = y1;
			line[num].y2 = y2;
			line[num].flag = -1;
			y[num++] = y2;
		}
		sort(line+1, line+num, cmp);
		sort(y+1, y+num);
		build(1, 1, num-1);
		update(1,line[1]);
		double ans = 0;
		cout<<tree[1].len <<' '<< tree[2].len<<' '<<tree[3].len <<endl;
	/*	for (int i = 2; i < num; ++i)
		{
			ans += tree[1].len * (line[i].x - line[i-1].x);
			update(1,line[i]);
		}
		printf("Test case #%d\n", Case++);
		printf("Total explored area: %.2lf\n\n", ans);*/
	}
	return 0;
}

