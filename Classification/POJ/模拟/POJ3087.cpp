#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

const int N = 105;

int t, c;
char s1[N], s2[N], s12[N<<1], s[N<<1], ans;

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &c);
		scanf("%s\n%s\n%s", s1, s2, s12);
		map<string, bool>vis;
		vis[s12] = true;
		ans = 0;
		while (true)
		{
			int tmp = 0;
			for (int i = 0; i < c; i++)
			{
				s[tmp++] = s2[i];
				s[tmp++] = s1[i];
			}
			ans++;
			s[tmp] = '\0';
			if (strcmp(s, s12) == 0)
			{
				printf("%d %d\n", cas, ans);
				break;
			}
			else if (vis[s])
			{
				printf("%d %d\n", cas, -1);
				break;
			}
			vis[s] = true;
			for (int i = 0; i < c; i++)
			{
				s1[i] = s[i];
				s2[i] = s[i+c];
			}
			s1[c] = s2[c] = '\0';
 		}
	}
	return 0;
}