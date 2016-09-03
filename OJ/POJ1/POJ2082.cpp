//数据结构——堆栈，紧贴x轴有一些互相挨着的矩形，给定每个矩形的长宽，问它们可以形成的最大矩形是多少。o^n复杂度
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

struct rec
{
	int w,h;
}data;

int main()
{
	int n,ans,i,lasth,totalw,curarea;
	while(scanf("%d",&n)&&n!=-1)
	{
		ans=0;
		stack<rec>s;
		lasth=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&data.w,&data.h);
			if(data.h>=lasth)
			  s.push(data);
			else
			{
				totalw=0;
				curarea=0;
				while(!s.empty()&&data.h<s.top().h)
				{
					totalw+=s.top().w;
					curarea=totalw*s.top().h;
					if(curarea>ans)
						ans=curarea;
					s.pop();
				}
				totalw+=data.w;
				data.w=totalw;
				s.push(data);
			}
			lasth=data.h;
		}
		totalw=0;
		curarea=0;
		while(!s.empty())
		{
			totalw+=s.top().w;
			curarea=totalw*s.top().h;
			if(curarea>ans)
			  ans=curarea;
			s.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
			
