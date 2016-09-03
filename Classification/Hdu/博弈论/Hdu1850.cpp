//Hdu1850 Being a Good Boy in Spring Festival N态到P态的方法数
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, a[1050];

int main()
{
	int i, ans, sum, tm;
	while (scanf("%d", &n),n)
	{
		scanf("%d", &a[1]);
		ans = a[1];
		sum  = 0;
		for (i = 2; i <= n; i++)
		{
			scanf("%d", &a[i]);
			ans ^= a[i];
		}
//		cout<<"ans:"<<ans<<endl;
		for (i = 1; i <= n; i++)
		{
			tm = ans ^ a[i] ^ 0;
		//	cout<<tm<<endl;
			if (tm < a[i])
			  sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}


