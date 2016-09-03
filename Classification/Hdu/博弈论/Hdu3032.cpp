//在Nim基础上加上可拆分规则，数据大，打表找sg规律
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1000010;
int sg[N];

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		int ans = 0, x;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x % 4 == 3)
			  x++;
			else if (x % 4 == 0)
			  x--;
			ans ^= x;
		}
		if (ans)
		  printf("Alice\n");
		else
		  printf("Bob\n");
	}
	return 0;
}
