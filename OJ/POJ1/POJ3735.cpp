//¾ØÕó¿ìËÙÃÝ
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 105
using namespace std;
int n,m,k;
struct Mat
{
	long long m[N][N];
	void mem()
	{
	//	memset(m,0,sizeof(m));
		fill(m[0], m[n+2], 0);
	}
	void init()
	{
		mem();
		for(int i=0;i<=n;i++)
		  m[i][i]=1;
	}
};
Mat T,A;

Mat multi(const Mat &a,const Mat &b)
{
	Mat c;
	c.mem();
	int i,j,k;
	for(k=0;k<=n;k++)
	  for(i=0;i<=n;i++)
		if(a.m[i][k])
		  for(j=0;j<=n;j++)
			c.m[i][j]+=a.m[i][k]*b.m[k][j];
	return c;
}

Mat power(Mat a,int n)
{
	Mat ans;
	ans.init();
	while(n)
	{
		if(n&1)
		{
			ans=multi(ans,a);
		}
		a=multi(a,a);
		n>>=1;
	}
	return ans;
}
int main()
{
	long long i,j,a,b;
	long long temp;
	char s[5];
	Mat ans;
	while(scanf("%d%d%d",&n,&m,&k)&&(n||m||k))
	{
		A.mem();
		A.m[0][0]=1;
		T.init();
		for(i=0;i<k;i++)
		{
			scanf("%s",s);
			if(s[0]=='g')
			{
				scanf("%d",&a);
				T.m[0][a]++;
			}
			else if(s[0]=='e')
			{
				scanf("%d",&a);
				for(j=0;j<=n;j++)
				  T.m[j][a]=0;
			}
			else
			{
				scanf("%d%d",&a,&b);
				for(j=0;j<=n;j++)
				{
					temp=T.m[j][a];
					T.m[j][a]=T.m[j][b];
					T.m[j][b]=temp;
				}
			}
		}
		ans=multi(A,power(T,m));
		for(i=1;i<=n;i++)
		  printf("%lld ",ans.m[0][i]);
		printf("\n");
	}
	return 0;
}
