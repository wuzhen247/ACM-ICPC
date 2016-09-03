#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int t, n, a[60];
double dis[120], ans;

bool cmp(double a, double b)
{
	return a > b;
}

double judge(double tm)
{
	int dir = 0;
	for (int i = 1; i < n-1; i++)
	{
		if (!dir)
		{
			if (a[i]-a[i-1] >= tm)
				dir = 0;
			else if (a[i+1]-a[i] >= tm)
				dir = 1;
			else
				return false;
		}
		else
		{
			if (a[i-1]+tm == a[i])
			{
				dir = 0;
				continue;
			}
			if (a[i]-a[i-1] >= 2*tm)
			{
				dir = 0;
				continue;
			}
			if (a[i+1]-a[i] >= tm)
				dir = 1;
			else
				return false;
		}
	}
	return true;
}

int main()
{
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
				scanf("%d", &a[i]);
			sort(a, a+n);
			for (int i = 1; i < n; i++)
			{
				dis[i*2-1] = a[i]-a[i-1];
				dis[i*2] = (a[i]-a[i-1])/2.0;
			}
			sort(dis+1, dis+2*n-1, cmp);
			ans = -1;
			for (int i = 1; i <= 2*n-2; i++)
			{
				if (judge(dis[i]))
				{
					ans = dis[i];
					break;
				}
			}
			printf("%.3lf\n", ans);
		}
	}
	return 0;
}