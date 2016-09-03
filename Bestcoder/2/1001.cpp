//TIANKENG’s restaurant, 按时间计算椅子
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1500;
int n, t, p[N], ans;

inline int max(int a, int b)
{
	return a > b? a:b;
}


int main()
{
	int s, e, a, b, num;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		memset(p, 0, sizeof(p));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			scanf("%d:%d", &a, &b);
			s = a * 60 + b;
			scanf("%d:%d", &a, &b);
			e = a * 60 + b;
			p[s] += num;
			p[e] -= num;
		}
		for (int i = 1; i < 1440; i++)
		{
			p[i] += p[i-1];
			ans = max(ans, p[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}