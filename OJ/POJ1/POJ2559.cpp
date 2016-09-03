//与POJ2082相同，单调栈，注意越界
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct rec
{
	int w,h;
}data;

int main()
{
	int n,lasth,i;
	long long ans,area,w;
	while(scanf("%d",&n)&&n)
	{
		lasth=0;
		stack<rec>s;
		ans=0;
		for(i=0;i<n;i++)
		{
			data.w=1;
			scanf("%d",&data.h);
			if(data.h>=lasth)
			  s.push(data);
			else
			{
				w=0;
				area=0;
				while(!s.empty()&&s.top().h>data.h)
				{
					w+=s.top().w;
					area=w*s.top().h;
					if(area>ans)
					  ans=area;
					s.pop();
				}
				data.w+=w;
				s.push(data);
			}
			lasth=data.h;
		}
		w=0;
		area=0;
		while(!s.empty())
		{
			w+=s.top().w;
			area=w*s.top().h;
			if(area>ans)
			  ans=area;
			s.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
