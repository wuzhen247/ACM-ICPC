//POJ3377 Ferry Lanes dijstra ÕºπÃ∂®£¨±‹√‚Ω®Õº
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define N 1000050
using namespace std;

const long long INF = (long long)(1LL<<63-1);
int t, n, m, src, aim, x1, y1, x2, y2;
bool vis[N<<1];
long long dis[N<<1], e1[N], e2[N], e3[N];

struct Node
{
	int v;
	long long d;
	bool operator < (const Node &other) const
	{
		return d > other.d;
	}
}tm;



void init()
{
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	n = t*2+2;
	m = 3*t+1;
	int i;
	for (i = 1; i <= n; i++)
	  dis[i] = INF;
	memset(vis, false, sizeof(vis));
	for (i = 1; i <= t; i++)
	  scanf("%lld", &e1[i]);
	for (i = 1; i <= t+1; i++)
	  scanf("%lld", &e2[i]);
	for (i = 1; i <= t; i++)
	  scanf("%lld", &e3[i]);
}

void getsa()
{
	switch(x1)
	{
		case 0:src = y1+1;break;
		case 1:src = y1+t+2;break;
	}
	switch(x2)
	{
		case 0:aim = y2+1;break;
		case 1:aim = y2+t+2;break;
	}
	long long tm;
	if (src > aim)
	{
		tm = src;
		src = aim;
		aim = tm;
	}
}

void dijstra(int src)
{
	dis[src] = 0;
	priority_queue<Node>q;
	tm.v = src;
	tm.d = 0;
	q.push(tm);
	int i, n1, n2, n3;
	for (i = 1; i <= n; i++)
	{
		while (!q.empty() && vis[q.top().v])
		  q.pop();
		if (q.empty())	break;
		Node pre = q.top();
		q.pop();
		vis[pre.v] = true;
//		cout<<pre.v<<endl;
		if (pre.v <= t+1)
		{
			n1 = pre.v+1;
			n2 = pre.v-1;
			n3 = pre.v+t+1;
		//	cout<<n1<<' '<<n2<<' '<<n3<<' '<<pre.d<<endl;
			if (n1 <= t+1)
			{
				dis[n1] = min(dis[n1], pre.d + e1[pre.v]);
			//	if(n1==3) cout<<dis[n1]<<endl;
				if (!vis[n1])
				{
					tm.v = n1, tm.d = dis[n1];
					q.push(tm);
				}
			}
			if (n2 >= 1)
			{
				dis[n2] = min(dis[n2], pre.d + e1[pre.v-1]);
				if (!vis[n2])
				{
					tm.v = n2, tm.d = dis[n2];
					q.push(tm);
				}
			}
			dis[n3] = min(dis[n3], pre.d + e2[pre.v]);
			if (!vis[n3])
			{
				tm.v = n3, tm.d = dis[n3];
				q.push(tm);
			}
		}
		else
		{
			n1 = pre.v+1;
			n2 = pre.v-1;
			n3 = pre.v-t-1;
			if (n1 <= n)
			{
			//	if (n1==7)	cout<<dis[n1]<<' '<<pre.v<<endl;
				dis[n1] = min(dis[n1], pre.d + e3[pre.v-t-1]);
			//	if (n1==7)	cout<<dis[n1]<<endl;
				if (!vis[n1])
				{
					tm.v = n1, tm.d = dis[n1];
					q.push(tm);
				}
			}
			if (n2 > 1+t)
			{
				dis[n2] = min(dis[n2], pre.d + e3[pre.v-t-2]);
				if (!vis[n2])
				{
					tm.v = n2, tm.d = dis[n2];
					q.push(tm);
				}
			}
			dis[n3] = min(dis[n3], pre.d + e2[pre.v-t-1]);
			if (!vis[n3])
			{
				tm.v = n3, tm.d = dis[n3];
				q.push(tm);
			}
		}
	}
}

int main()
{
	while (scanf("%d", &t) && t)
	{
		init();
		getsa();
//		cout<<dis[10]<<endl;
//		cout<<src<<' '<<aim<<endl;
		dijstra(src);
//		for (int i= 1; i<=n;i++)
//		  cout<<i<<':'<<dis[i]<<endl;
		printf("%lld\n", dis[aim]);
	}
	return 0;
}
