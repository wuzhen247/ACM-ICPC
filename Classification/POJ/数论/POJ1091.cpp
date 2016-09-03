//POJ1091 ���� ��ʵ�ʣ�������n��m��Ҫ����������Լ��(x1,x2,...,xn,m)=1��x1,...,xn��//����sum�����б�������0 <= x1,x2,...,xn <= m
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll __int64
using namespace std;

ll p[50],nprime,a[50],temp,ans,fx;
int n,m;

ll pow(ll a, int b)
{
	ll tm=1;
	while(b--)	tm*=a;
	return tm;
}

void getprime(int tm)
{
	nprime=0;
	for(int i=2;i*i<=tm;i++)
	{
		if(tm%i==0)
		{
			p[nprime++]=i;
			while(tm%i==0)	tm/=i;
		}
	}
	if(tm>1)	p[nprime++]=tm;
}

void dfs(int pos,int cnt,int num)
{
	if(cnt==num)
	{
		int tm=m;
		for(int i=0;i<cnt;i++)
		  tm/=a[i];
		temp+=pow(tm,n);
	}
	for(int i=pos;i<nprime;i++)
	{
		a[cnt]=p[i];
		dfs(i+1,cnt+1,num);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int i;
	fx=0;
	getprime(m);
	for(i=1;i<=nprime;i++)
	{
		temp=0;
		dfs(0,0,i);
		if(i%2)	fx+=temp;
		else	fx-=temp;
	}
	ans=pow(m,n)-fx;
	printf("%lld\n",ans);
	return 0;
}
