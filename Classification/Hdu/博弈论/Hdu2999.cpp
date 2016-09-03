//博弈 取连续石子 sg
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k, s[110], sg[1010];

int getsg(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool vis[1050];
	int tm;
	memset(vis, false, sizeof(vis));
	for (int i = 0; x >= s[i] && i < n; i++)
	{
		tm = x - s[i];
		for (int j = 0; j <= tm/2; j++)
			vis[getsg(j)^getsg(tm-j)] = true;
	}
	for (int i = 0; ;i++)
		if (!vis[i])
			return sg[x] = i;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(sg, -1, sizeof(sg));
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		sort(s, s+n);
		int num = 0, x;
		for (int i = 1; i < n; i++)
			if (s[i] != s[i-1])
				s[++num] = s[i];
		n = num + 1;
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &x);
			if (getsg(x))
				printf("1\n");
			else 
				printf("2\n");
		}
	}
}