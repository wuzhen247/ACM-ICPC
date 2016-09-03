//Nim²©ÞÄ
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n, ans, tm;
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tm);
			ans ^= tm;
		}
		if (ans)
		  printf("Yes\n");
		else
		  printf("No\n");
	}
	return 0;
}
