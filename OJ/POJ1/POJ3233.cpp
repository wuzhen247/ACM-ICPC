//¾ØÕó¿ìËÙÃİ 
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 35
using namespace std;
struct Matrax
{
	int m[N][N];
};
Matrax per,a;
int n,k,m;
void init()
{
	int i,j;
	memset(per.m,0,sizeof(per.m));
	for(i=0;i<n;i++)
	{
		per.m[i][i]=1;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a.m[i][j]);
			a.m[i][j]%=m;
		}
	}
}
Matrax multi(Matrax a,Matrax b)
{
	Matrax c;
	int i,j,k;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
		  c.m[i][j]=0;
		  for(k=0;k<n;k++)
			c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%m;
		 // c.m[i][j]%=m;
	  }
	return c;
}
Matrax power(int k)
{
	Matrax p=a,ans=per;
	while(k)
	{
		if(k&1)
		{
			ans=multi(ans,p);
		}
		p=multi(p,p);
		k>>=1;
	}
	return ans;
}
Matrax add(Matrax a,Matrax b)
{
	int i,j;
	Matrax c;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		c.m[i][j]=(a.m[i][j]+b.m[i][j])%m;
	return c;
}
Matrax sum(int k)
{
	if(k==1) return a;
	Matrax temp,b;
	if(k==0)
	{
		memset(b.m,0,sizeof(b.m));
		for(int i=0;i<n;i++)
		b.m[i][i]=1;
		return b;
	}
	if(k%2==0)
	{
		temp=sum(k/2);
		b=add(temp,multi(temp,power(k/2)));
	}
	else
	{
		b=add(sum(k-1),power(k));
	}
	return b;
}

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	{
		init();
		Matrax s;
		s=sum(k);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			  printf("%d ",s.m[i][j]);
			printf("%d\n",s.m[i][j]);
		}
	}
	return 0;
}

