//POJ3250 Bad Hair Day µ¥µ÷Õ»
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
	int n;
	long long ans=0ll,lasth;
	stack<long long>s;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&lasth);
		while(!s.empty()&&s.top()<=lasth)
		  s.pop();
		ans+=s.size();
		s.push(lasth);
	}
	printf("%lld\n",ans);
	return 0;
}
