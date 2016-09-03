/*威尔逊定理：
若p为质数，则
p|(p-1)!+1
亦：(p-1)! ≡ p-1 ≡ -1(mod p)
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 3000005+10;
int ans[N];

bool vis[N], f[N/3];
int p[N/3], np;

void getprime()
{
	memset(vis, true, sizeof(vis));
	memset(f, false, sizeof(f));
	np = 0;
	for (int i = 2; i < N; i++)
	{
		if (vis[i])
		{
			p[++np] = i;
			if ((i-7)%3==0)
				f[(i-7)/3] = true;
		}
		for (int j = 1; j <= np && p[j] * i < N; j++)
		{
			vis[p[j]*i] = false;
			if (i % p[j] == 0)
				break;
		}
	}
}

int main()
{
	int t, n;
	getprime();
	ans[0] = 0;
	for (int i = 1; i < N; i++)
	{
		if (f[i] == true)
			ans[i] = ans[i-1]+1;
		else
			ans[i] = ans[i-1];
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}