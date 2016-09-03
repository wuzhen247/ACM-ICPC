#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, a[6];

int main()
{
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			for (int i = 0; i < 6; i++)
				scanf("%d", &a[i]);
			sort(a, a+6);
			if (a[4]+a[5] > a[1]+a[2]+a[3])
				printf("Grandpa Shawn is the Winner!\n");
			else
				printf("What a sad story!\n");
		}
	}
	return 0;
}