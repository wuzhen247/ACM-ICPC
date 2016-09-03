#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100000+5;
int t, n, m, q, a[N], b[N],ans[N<<1];

int main()
{
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; i++)
				scanf("%d", &a[i]);
			sort(a, a+n);
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			a[n-1]++;
			for (int i = n-1; i > 0; i--)
			{
				if (b[i] - b[i-1] == 1)
					a[i-1] = a[i];
				else
					a[i-1]++;
			}
			for (int i = 1; i < 2*N; i++)
				ans[i] = i;
			for (int i = 0; i < n; i++)
				ans[b[i]] = a[i];
			while (m--)
			{
				scanf("%d", &q);
				printf("%d\n", ans[q]);
			}
			
		}
	}
	return 0;
}