/*第一类斯特林数
s(p,k)的一个的组合学解释是：将p个物体排成k个非空循环排列的方法数。
 
s(p,k)的递推公式： s(p,k)=(p-1)*s(p-1,k)+s(p-1,k-1) ,1<=k<=p-1
边界条件：s(p,0)=0 ,p>=1  s(p,p)=1  ,p>=0
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;

ll fac[22];
ll stir[22][22];
int t, n, k;
ll ans;

int main()
{
	fac[0] = fac[1] = 1;
	for (int i = 2; i < 21; i++)
		fac[i] = fac[i-1] * i;
	for (int i = 1; i < 21; i++)
	{
		stir[i][0] = 0;
		stir[i][i] = 1;
		for (int j = 1; j < i; j++)
			stir[i][j] = stir[i-1][j-1] + (i-1) * stir[i-1][j];
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		if (n == 1)
		{
			printf("0.0000\n");
			continue;
		}
		ans = 0;
		for (int i = 1; i <= k; i++)
			ans += stir[n][i] - stir[n-1][i-1];
		printf("%.4lf\n", 1.0 * ans / fac[n]);
	}
	return 0;
}