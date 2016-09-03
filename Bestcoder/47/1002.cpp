#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 100000+5;
int a[N], b[N], t, n, m;
ll ans;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++)
			scanf("%d", &b[i]);
		sort(a+1, a+n+1);
		sort(b+1, b+m+1);
		int p1=n, p2=1;
		ans = 0;
		while (a[p1] > b[p2])
		{
			if (p1 < 0 || p2 > m)
				break;
			ans += a[p1]-b[p2];
			p1--, p2++;
		}
		cout<<ans<<endl;

	}
	return 0;
}