//Calendar Game 博弈的重要技巧，对数据的奇偶进行分析
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int t, y, m, d;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &y, &m, &d);
		if ((m+d)%2==0 || (d==30 && (m==9 || m==1)))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}