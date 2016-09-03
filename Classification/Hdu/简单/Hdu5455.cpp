#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1000000+100;
char s[N];
int t, ans, len;
int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%s", s);
		len = strlen(s);
		int last, now, first;
		bool flag = false;
		ans = 0;
		for (last = 0; last < len; last++)
		{
		    if (s[last] != 'c' && s[last] != 'f')
		    {
		        flag = true;
		        break;
            }
			if (s[last] == 'c')
			{
				ans++;
				first = last;
				break;
			}
		}
		for (now = last+1; now < len; now++)
		{
		    if (s[now] != 'c' && s[now] != 'f')
		    {
		        flag = true;
		        break;
            }
			if (s[now] == 'c')
			{
				ans++;
				if (now - last - 1 < 2)
				{
					flag = true;
					break;
				}
				last = now;
			}
		}
		if (!flag && ans && now - last -1 + first < 2)
			flag = true;
		printf("Case #%d: ", cas);
		if (flag)
			printf("-1\n");
		else
		{
			if (ans == 0)
				ans = (len+1)>>1;
			printf("%d\n", ans);
		}
	}
	return 0;
}
