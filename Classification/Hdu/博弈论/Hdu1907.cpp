
#include <iostream>
#include <cstring>
#include <cstdio>

int main()
{
	int t, ans, tm, i, n;
	scanf("%d", &t);
	bool f;
	while(t--)
	{
		scanf("%d", &n);
		ans = 0;
		f = false;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &tm);
			if (tm > 1)
			  f = true;
			ans ^= tm;
		}
		if ((ans && f) || ( !ans && !f))
		  printf("John\n");
		else
		  printf("Brother\n");
	}
	return 0;
}
