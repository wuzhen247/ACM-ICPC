//POJ1740 ²©ÞÄ ÆæÊý¶Ñ±ØÊ¤£¬Å¼Êý¶ÑÅÐ×´Ì¬
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[15];

int main()
{
	int n, i, tm;
	bool f;
	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (n % 2 )
		  printf("1\n");
		else
		{
			sort(a,a+n);
			for (i = 1, f = false; i < n; i+=2)
				if (a[i] != a[i-1])
				{
					f = true;
					break;
				}
			if (f)
			  printf("1\n");
			else
			  printf("0\n");
		}
	}
	return 0;
}
