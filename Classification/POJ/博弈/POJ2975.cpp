//Nim博弈 N态到P态的走法数
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, a[1050];

int main()
{
	int i, ans, sum, tm;
	while (scanf("%d", &n),n)
	{
		scanf("%d", &a[1]);
		ans = a[1];
		sum  = 0;
		for (i = 2; i <= n; i++)
		{
			scanf("%d", &a[i]);
			ans ^= a[i];
		}
		for (i = 1; i <= n; i++)
		{
			tm = ans ^ a[i] ^ 0;
			if (tm < a[i])
			  sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}

