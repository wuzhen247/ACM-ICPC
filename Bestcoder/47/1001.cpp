#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1000+5;
int t, n, a[N], p;
ll ans1;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &p);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		ll tmp = 0, ans = 0;
		int tm;
		ans1 = p;
		for (int k = 1; k <= n; k++)
		{
			tm = a[k], a[k] = p;
			tmp = ans = a[1];
			for (int i = 2; i <= n; i++)
			{
				tmp += a[i];
				ans = max(ans, tmp);
				if (tmp < 0)
					tmp = 0;
			}
			ans1 = max(ans1, ans);
			a[k] = tm;
		}
		cout<<ans1<<endl;
	}
	return 0;
}