/*ZOJ3529 A Game Between Alice and Bob
 *
 * ����n������ÿһ�������Խ�ĳ�����滻Ϊ�������ӣ��������滻Ϊ���������������ߣ�ֱ��ĳ�����߲����������ˡ������˭��Ӯ���������ʤ�����һ����n<=10��ÿ����<=5000000.*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 5000050
using namespace std;

bool vis[N];
int p[N], np, n;
int mp[N], a[100050],dp[N];

void getprime()
{
	memset(vis, true, sizeof(vis));
	int i,j;
	np = 0;
	vis[0] = vis[1] = false;
	for (i = 1; i < N; i++)
	  mp[i] = i;
	for (i = 2; i < N ; i++)
	{
		if (vis[i])
		{
		  p[++np] = i;
		}
		for (j = 1; j <= np && p[j]*i < N; j++)
		{
			vis[i*p[j]] = false;
			mp[i*p[j]] = p[j];
			if (i%p[j]==0)
			  break;
		}
	}
}

void getn()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 2; i < N; i++)
	  dp[i] = dp[i/mp[i]] + 1;
}


int main()
{
	int c = 1, i, ans;
	getprime();
	getn();

	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			ans ^= dp[a[i]];
		}
//		cout<<ans<<endl;
		for (i = 1; i <= n; i++)
		{
			if (dp[a[i]] > (ans ^ dp[a[i]] ))
			  break;
		}
		printf("Test #%d: ",c++);
		if (ans)
		  printf("Alice %d\n",i);
		else
		  printf("Bob\n");
	}
	return 0;
}
