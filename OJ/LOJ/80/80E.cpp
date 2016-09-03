#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100500
using namespace std;

int n, mid;
long long h[N], w[N], l, mh;

int main()
{
	int i;
	long long sum, f, r;;
	while (scanf("%d%d", &n, &l) != EOF)
	{
		sum = 0;
		mh = mid = -1;
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &h[i]);
			if (h[i] > mh)
			{
				mh= h[i];
				mid = i;
			}
		}
		for (i = 1; i <= n; i++)
		  scanf("%lld", &w[i]);
		f = h[1];
		for (i = 1; i < mid; i++)
		{
			f = max(f,h[i]);
			sum += (f-h[i]) * w[i] * l;
		}
		r = h[n];
		for (i = n; i > mid; i--)
		{
			r = max (r, h[i]);
			sum += (r-h[i]) * w[i] * l;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
