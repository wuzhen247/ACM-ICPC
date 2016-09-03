//优先队列
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int> >q;
	int n,i,tm,a,b;
	long long sum,ans;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d",&tm);
		q.push(tm);
	}
	ans=0;
	while(q.size()>1)
	{
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		ans += a+b;
		sum = a+b;
		q.push(sum);
	}
	printf("%lld\n", ans);
	return 0;
}