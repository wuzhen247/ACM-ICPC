//ËØÒò×ÓÎª2,3,5
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int p1,p2,p3,i,n;
	long long a[1505];
	a[1]=1;
	p1=p2=p3=1;
	for(i=2;i<1505;i++)
	{
		a[i]=min(a[p1]*2,min(a[p2]*3,a[p3]*5));
		if(a[i]==a[p1]*2)
		  p1++;
		if(a[i]==a[p2]*3)
		  p2++;
		if(a[i]==a[p3]*5)
		  p3++;
	}
	while(scanf("%d",&n)&&n)
		printf("%lld\n",a[n]);
	return 0;
}

