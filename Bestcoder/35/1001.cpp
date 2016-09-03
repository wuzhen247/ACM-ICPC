//m*n/(m+n)
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
	if (!b)	return a;
	return gcd(b, a%b);
}

int main()
{
	int  m, n, a;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		a = gcd(m*n, m+n);
		printf("%d/%d\n",m*n/a, (m+n)/a);
	}
	return 0;
}