#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10050;
bool f[N];
int p[N], np, a[11], num[N];

void getprime()
{
	np = 0;
	memset(f, true, sizeof(f));
	int i, j;
	for (i = 2; i < N; i++)
	{
		if (f[i])
			p[++np] = i;
		for (j = 1; j <= np && i * p[j] < N; j++)
		{
			f[p[j] * i] = false;
			if (i % p[j] == 0)
				break;
 		}
	}
}

void split(int n)
{
	for (int i = 1; p[i] * p[i] <= n; i++)
	{
		if (n % p[i] == 0)
		{
			while(n % p[i] == 0)
			{
				n /= p[i];
				num[p[i]]++;
			}
		}
	}
	if (n != 1)
		num[n]++;
}

int main()
{
	getprime();
//	for(int j =1; j < 100; j++)
//		cout<<p[j]<<' ';
	long long ans = 1ll;
	memset(num, 0, sizeof(num));
	int i, M = -1;
	for (i = 1; i <= 10; i++)
	{
		scanf("%d", &a[i]);
		M = max(M, a[i]);
		split(a[i]);
	}
	for (i = 1; i <= M; i++)
	{
		if (num[i])
			ans *= (num[i]+1);
	}
	printf("%lld\n",ans%(10ll));
	return 0;
}