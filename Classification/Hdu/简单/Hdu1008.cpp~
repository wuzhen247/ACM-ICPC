#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n, sum, tm1, tm2;
	while (scanf("%d", &n), n)
	{
		sum = 0;
		tm1 = 0;
		while (n--)
		{
			scanf("%d", &tm2);
			if (tm1 == tm2)
				sum += 5;
			else if (tm2 > tm1)
				sum += (tm2 - tm1)*6 + 5;
			else
				sum += (tm1 - tm2)*4 + 5;
			tm1 = tm2;
		}
		printf("%d\n", sum);
	}
	return 0;
}
