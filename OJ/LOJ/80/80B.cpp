#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[2050];

int main()
{
	int i, j, sum;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		sum  = 0;
		for (i = 1; i <= n; i++)
		  scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		if (a[1]>0)
		  sum += a[1];
		for (i = 2; i <= n; i++)
		{
			if (a[i] - a[i-1] > 200)
			  sum += (a[i]-a[i-1]-200)*2;
		}
		if (2000-a[n]>100)
		  sum += (2000-a[n])*2-200;
		if (a[1] > 200)
		  sum += a[1]-200;
		if (sum > m)
		  printf("HeHe~\n");
		else
		  printf("HaHa~\n");
	}
	return 0;
}
