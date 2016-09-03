//整数划分问题 生成函数法
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[125], b[125];

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i <= n; i++)
		{
			a[i] = 1;
			b[i] = 0;
		}
		for (i = 2; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
				for (k = 0; k+j <= n; k += i)
					b[k+j] += a[j];
			for (j = 0; j <= n; j++)
			{
				a[j] = b[j];
				b[j] = 0;
			}
		}
		printf("%d\n", a[n]);
	}
	return 0;
}