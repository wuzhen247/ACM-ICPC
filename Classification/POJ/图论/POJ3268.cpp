//dijstra max(来程+返程）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1005;
const int M = 100005;
const int INF=0x3f3f3f3f;

struct Edge
{
	int v, c, next;
}p[M];

struct Tmp
{
	int u, v, c;
}tm[M];

struct Edg
{
	int v, c;
	Edg(int v, int c):v(v), c(c){}
	bool operator < (const Edg &other) const
	{
		return c > other.c;
	}
};

int n, m, x, e, head[N], dis[N], dis1[N];
bool vis[N];

void init()
{
	memset(head, -1, sizeof(head));
	e = 0;
}

void add(int u, int v, int c)
{
	p[e].v = v, p[e].c = c;
	p[e].next = head[u], head[u] = e++;
}

void dijstra(int st)
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[st] = 0;
	priority_queue<Edg> q;
	q.push(Edg(st, dis[st]));
	for (int i = 0; i < n; i++)
	{
		while (!q.empty() && vis[q.top().v])
			q.pop();
		if (q.empty())	break;
		Edg pre = q.top();
		vis[pre.v] = true;
		q.pop();
		for (int j = head[pre.v]; j != -1; j = p[j].next)
		{
			if (vis[p[j].v])	continue;
			if (dis[p[j].v] > dis[pre.v] + p[j].c)
			{
				dis[p[j].v] = p[j].c + dis[pre.v];
				q.push(Edg(p[j].v, dis[p[j].v]));
			}
		}
	}

}

int main()
{
	int u, v, c, ans;
	while (scanf("%d%d%d", &n, &m, &x) != EOF)
	{

		for (int i = 1; i <= m; i++)
			scanf("%d%d%d", &tm[i].u, &tm[i].v, &tm[i].c);

		init();
		for (int i = 1; i <= m; i++)
			add(tm[i].u, tm[i].v, tm[i].c);
		dijstra(x);
		for (int i = 1; i <= n; i++)
			dis1[i] = dis[i];

		init();
		for (int i = 1; i <= m; i++)
			add(tm[i].v, tm[i].u, tm[i].c);
		dijstra(x);

		ans = -1;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dis1[i] + dis[i]);
		printf("%d\n", ans);
	}
	return 0;
}