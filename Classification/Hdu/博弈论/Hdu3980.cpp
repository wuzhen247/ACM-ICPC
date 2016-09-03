//将环拆成链，非递归求sg
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
int sg[1010];
bool vis[1010];

void getsg()
{
	int tm;
	memset(sg, -1, sizeof(sg));
	for (int i = 0; i <1010; i++)
	{
		memset(vis, false, sizeof(vis));
		if (i < m)
		{
			sg[i] = 0;
			continue;
		}
		tm = i - m;
		for (int j = 0; j <= (tm>>1); j++)
			vis[sg[j]^sg[tm-j]] = true;
		for (int j = 0;;j++)
			if (!vis[j])
			{
				sg[i] = j;
				break;
			}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca++)
	{
		scanf("%d%d", &n, &m);
		getsg();
		printf("Case #%d: ", ca);
		if (n == m)
			printf("aekdycoin\n");
		else if (n < m)
			printf("abcdxyzk\n");
		else if (sg[n-m])
			printf("abcdxyzk\n");
		else
			printf("aekdycoin\n");

	}
	return 0;
}