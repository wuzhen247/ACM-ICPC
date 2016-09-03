//POJ1308 Is It A Tree?  并查集
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 10005;
int f[N], d[N];
bool vis[N];

int Init()
{
	for (int i = 0; i < N; i++)
	{
		f[i] = i;
		vis[i] = false;
	}
}

int getfather(int x)
{
	if (f[x] == x)
		return x;
	return f[x] = getfather(f[x]);
}

bool Union(int x, int y)
{
	int tm = getfather(x);
	if (tm == y)
		return false;
	else
	{
		f[y] = tm;
		return true;
	}
}

int main()
{
	int a, b, n, x, y, fa, num, ca = 0;
	bool flag;
	while (scanf("%d%d", &a, &b))
	{
		if (a == -1 && b == -1)
			break;
		if (a == 0 && b == 0)
		{
			printf("Case %d is a tree.\n", ++ca);
			continue;
		}
		Init();
		memset(d, 0, sizeof(d));
		flag = false, num = 0;
		d[b]++;
		vis[a] = vis[b] = true;
		if (!Union(a, b))
			flag = true;
		while (scanf("%d%d", &a, &b),(a || b))
		{
			if (flag == false)
			{
				d[b]++;
				vis[a] = vis[b] = true;
				if (!Union(a, b))
					flag = true;
			}
		}
		for (int i = 1; i < N && !flag; i++)
		{
			if (vis[i])
			{
				if (d[i] > 1)
					flag =true;
				if (num == 0)
				{
					num++;
					fa = getfather(i);
				}
				else
				{
					if (getfather(i) != fa)
						flag = true;
				}
			}
}
		printf("Case %d is ", ++ca);
		if (flag)
			printf("not a tree.\n");
		else
			printf("a tree.\n");
	}
	return 0;
}