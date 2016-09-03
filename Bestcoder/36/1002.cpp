//map 映射
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

map<int, int>p;
int n, m;

int main()
{
	int tm;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		p.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tm);
			p[tm]++;
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &tm);
			printf("%d\n", p[tm]);
			p[tm] = 0;
		}
	}
	return 0;
}