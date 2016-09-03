/*题意：一个仅有一行的棋盘上，初始时有n个棋子，每人轮流移动棋子，每次只能移动一枚棋子，
	棋子在移动时只能向左移动，不能跨过别的棋子或跳出棋盘
将所有棋子的初始坐标从小到大排序，从最后一枚向前两两配对。如果棋子数为奇数，
则将第一枚与坐标0配对
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1010];

int main()
{
	int t, n, ans, x;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		a[0] = 0;
		if (n % 2)
		{
			for (int i = 1; i <= n; i+=2)
				ans ^= (a[i]-a[i-1]-1);
		}
		else
		{
			for (int i = 2; i <= n; i+=2)
				ans ^= (a[i]-a[i-1]-1);
		}
		if (ans)
			printf("Georgia will win\n");
		else
			printf("Bob will win\n");
	}
	return 0;
}