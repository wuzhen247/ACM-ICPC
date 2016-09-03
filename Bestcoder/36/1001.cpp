#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[100];
int n, ans, a[3];

int main()
{
	while (scanf("%s", s) != EOF)
	{
		memset(a, 0, sizeof(a));
		n = strlen(s);
		if (n < 3 || s[0] == s[n-1])
		{
			printf("NO\n");
			continue;
		}
		int i, j;
		for (i = j = 0; i < 3; i++)
		{
			for (j++;j < n; j++)
			{
				a[i]++;
				if (s[j] != s[j-1])
					break;
			}
			if (j >= n )
			{
				a[i]++;
				break;
			}
		}
		if (a[0] == a[1] && a[1] == a[2] && i < 3)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}