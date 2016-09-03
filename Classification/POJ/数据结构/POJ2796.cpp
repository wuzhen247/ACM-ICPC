//单调栈，输出左右端点，利用系统栈实现
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct rec
{
	int l,r,h;
	long long w;
}data;

int main()
{
	int n,i,l,r,lasth,tm,ll;
	long long totalw,ans,area;
	scanf("%d",&n);
	ans=totalw=area=lasth=0;
	l=r=1;
	stack<rec>s;
	for(i=1;i<=n;i++)
	{
		data.r=data.l=i;
		scanf("%d",&data.h);
		data.w=data.h;
		if(data.h>=lasth)
		  s.push(data);
		else
		{
			totalw=0,area=0,tm=s.top().r;
			while(!s.empty()&&s.top().h>data.h)
			{
				totalw+=s.top().w;
				area=(long long)totalw*s.top().h;	
				if(area>ans)
				{
					ans=area;
					l=s.top().l;
					r=tm;
				}
				ll=s.top().l;
				s.pop();
			}
			data.w+=totalw;
			data.l=ll;
			data.r=i;
			s.push(data);
			
		}
		lasth=data.h;
	}
	totalw=area=0;
	tm=s.top().r;
	while(!s.empty())
	{
		totalw+=s.top().w;
		area=totalw*s.top().h;
		if(area>ans)
		{
			ans=area;
			l=s.top().l;
			r=tm;
		}
		s.pop();
	}
	printf("%lld\n%d %d\n",ans,l,r);
	return 0;
}


