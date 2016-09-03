#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int t,i,j,k,ans,tm,n;
	scanf("%d",&t);
	while(t--)
	{
		ans=1<<30;
		scanf("%d",&n);
		for(i=1;i<=sqrt(n);i++)
		{
			if(n%i)
				continue;
			for(j=i;j<=sqrt(n);j++)
			{
				if((n/i)%j)
					continue;
				for(k=j;k<=n;k++)
				{
					if(i*j*k==n)
					{
						tm=2*(i*j+i*k+j*k);
						if(tm<ans)
							ans=tm;
					}
				}
			}
		}
		printf("%d\n",ans );
	}
	return 0;
}