//数圆中三角形
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 20121111;

int main()
{
	int t, n, ans;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca++)
	{
		scanf("%d", &n);
		switch(n)
		{
			case 1:
			case 2: ans = 0; break;
			case 3: ans = 1; break;
			case 4: ans = 8; break;
			case 5: ans = 35;break;
			case 6: ans = 32;break;
			default:ans = 5*n;break;
		}
		printf("Case #%d: %d\n", ca, ans%MOD);
	}
	return 0;
}