//抽屉原理
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int a[50005],use[1000005];

int main()
{
	int t,i,j,d,n;
	__int64 ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&d,&n);
		memset(use,0,sizeof(use));
			
		a[0]=0;
		use[0]++;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=(a[i-1]+a[i])%d;
			use[a[i]]++;
		}
		ans=0ll;
		for(i=0;i<d;i++)
		{
			if(use[i]>1)
				ans+=(__int64)use[i]*(use[i]-1)>>1;
		}
		printf("%lld\n",ans );
	}
	return 0;
}