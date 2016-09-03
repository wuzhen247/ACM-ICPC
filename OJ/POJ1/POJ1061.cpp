//扩展欧几里得算法
#include<iostream>
#include<cstdio>
typedef long long int64;
using namespace std;
int64 x,y,q;

void exgcd(int64 a,int64 b)
{
	if(b==0)
	{
		x=1,y=0,q=a;
	}
	else
	{
		exgcd(b,a%b);
		int64 temp=x;
		x=y,y=temp-a/b*y;
	}
}
int main()
{
	int64 a,b,m,n,l;
	cin>>a>>b>>m>>n>>l;
	exgcd(n-m,l);
	if((a-b)%q||m==n)
	{
		cout<<"Impossible\n";
		return 0;
	}
	else
	{
		int64 s=l/q;
		x=x*((a-b)/q);
		x=(x%s+s)%s;
		cout<<x<<endl;
	}
	return 0;
}

