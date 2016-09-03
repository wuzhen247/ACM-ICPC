//集合贪心（坐标轴）
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int c[205];

int main()
{
	int a,b,n,t,tm,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>b)
			{
				tm=a;
				a=b;
				b=tm;
			}
			if(a%2)
				a++;
			a/=2;
			if(b%2)
				b++;
			b/=2;
			while(a<=b)
			{
				c[a]++;
				a++;
			}
		}

		ans=0;
		for(i=0;i<205;i++)
			if(ans<c[i])
				ans=c[i];
		printf("%d\n", ans*10);
	}
	return 0;
}