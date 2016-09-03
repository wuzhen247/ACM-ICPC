#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int b[1000005];
int main()
{
	int n,q,a,x,ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		memset(b,0,sizeof(b));
		while(n--)
		{
			scanf("%d%d%d",&q,&a,&x);
			if(a==0)
			  ans+=10;
			else
			{
				if(x==1)
					ans+=40;
				else
					ans+=20;
				ans+=b[q]*10;
				b[q]++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
	
