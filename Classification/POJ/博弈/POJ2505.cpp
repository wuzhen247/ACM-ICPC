//2*9
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int main()
{
	ll n, p;
	int num = 1;
	while (scanf("%lld", &n) != EOF)
	{
		p = 1;
		num = 1;
		while (true)
		{
			p *= 9;
			if (p >= n)
				break;
			num++;
			p *= 2;
			if (p >= n)
				break;
			num++;
		}
		if (num % 2)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
	return 0;
}