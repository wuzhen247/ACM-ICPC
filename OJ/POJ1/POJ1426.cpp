//01序列为n的整数倍
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

int n;

long long bfs()
{
	queue<long long > q;
	while(!q.empty())
		q.pop();
	q.push(1);
	while(true)
	{
		long long tm = q.front();
		if(tm%n==0)
			return tm;
		q.pop();
		q.push(10*tm);
		q.push(10*tm+1);
	}
}

int main()
{
	while(scanf("%d",&n) && n)
	{
		printf("%lld\n", bfs());
	}
	return 0;
}