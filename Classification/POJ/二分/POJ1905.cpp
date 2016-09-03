//二分答案
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double l, n, c, lim, low, high, r, mid, x;
	while (scanf("%lf%lf%lf", &l, &n, &c))
	{
		if (l < 0 && n < 0 && c < 0)
			break;
		lim = (1+n*c)*l;
		if (n == 0 || c == 0 || l == 0)
		{
			printf("0.000\n");
			continue;
		}
		low = 0, high = l/2;
		while (high - low > 1e-4)
		{
			mid = (low+high)/2;
			r = mid/2 + l*l/8/mid;
			x = 2*asin(l/2/r);
			if (x*r >= lim)
				high = mid;
			else
				low = mid;
		}
		printf("%.3lf\n",mid);
	}
	return 0;
}