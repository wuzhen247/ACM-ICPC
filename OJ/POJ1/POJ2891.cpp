//计算线性同余方程组 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void exgcd(__int64 a,__int64 b,__int64 &d,__int64 &x,__int64 &y)
{
	if(b==0)
	{
		x=1,y=0,d=a;
		return ;
	}
	exgcd(b,a%b,d,x,y);
	__int64 temp=x;
	x=y;
	y=temp-a/b*y;
}
int main()
{
	__int64 a1,r1,a2,r2,a,b,c,x0,y0,d,t,n,i,j;
	bool f;
	while(scanf("%I64d",&n)!=EOF)
	{
		f=true;
		scanf("%I64d%I64d",&a1,&r1);
		for(i=1;i<n;i++)
		{
			scanf("%I64d%I64d",&a2,&r2);
			a=a1,b=a2,c=r2-r1;
			if(f==false) continue;
			exgcd(a,b,d,x0,y0);
			if(c%d!=0)
			{
			  f=false;
			}
			t=b/d;
			x0=(x0*(c/d)%t+t)%t;
			r1=a1*x0+r1;
			a1=a1*(a2/d);
		}
		if(f==false)
		  printf("-1\n");
		else
		  printf("%I64d\n",r1);
	}
	return 0;
}

