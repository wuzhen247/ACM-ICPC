//POJ2368 Buttons °ÍÊ²²©ÞÄ±äÐÎ
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{	
		for (i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
			  break;
		}
		if (i*i>n)
		  printf("%d\n", n-1);
		else
		{
			for (i=3; i<=n; i++)
			{
				if (n%i == 0)
				{
					printf("%d\n", i-1);
					break;
				}
			}
		}
	}
	return 0;
}
