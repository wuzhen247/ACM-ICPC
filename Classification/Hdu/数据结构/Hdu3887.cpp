//dfs序+树状数组
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#define N 100005
using namespace std;

struct Node
{
	int vex, next;
}edge[N<<1];

int n, m, h[N], tol, ans[N], c[N];
bool vis[N];

stack<int>s;

inline int lowbit(int x)
{
	return x & (-x);
}

int query(int k)
{
	int ans = 0;
	while(k > 0)
	{
		ans += c[k];
		k -= lowbit(k);
	}
	return ans;
}

void update(int pos, int k)
{
	while(pos <= n)
	{
	    c[pos] += k;
		pos += lowbit(pos);
	}
}

void addedge(int a, int b)
{
	edge[tol].vex = b;
	edge[tol].next = h[a];
	h[a] = tol++;
}

void dfs(int k)
{
	int pos, v, tm;
	s.push(k);
	while(!s.empty())
	{
		pos = s.top();
		if (vis[pos])
		{
			ans[pos] = query(pos-1) - ans[pos];
			s.pop();
			update(pos,1);
		}
		else
		{
			vis[pos] = true;
			ans[pos] = query(pos-1);
			for (int i = h[pos]; i != -1; i = edge[i].next)
			{
				tm = edge[i].vex;
				if(!vis[tm])
					s.push(tm);
			}
		}
	}
}

int main()
{
	int a, b, i;
	while(scanf("%d%d",&n,&m) && (n || m))
	{
		memset(h,-1,sizeof(h));
		memset(vis,false,sizeof(vis));
		tol = 1;
		for (i = 1; i < n; ++i)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
			addedge(b,a);
		}
		dfs(m);
		printf("%d", ans[1]);
		for (int i = 2; i <= n; ++i)
		{
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}