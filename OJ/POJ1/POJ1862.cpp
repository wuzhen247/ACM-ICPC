#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105];
int main()
{
	int n,i;
	double ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		printf("%.3lf\n", (double)a[0]);
		return 0;
	}
	sort(a,a+n);
	for(i=n-3,ans=2*sqrt(double(a[n-1]*a[n-2]));i>=0;i--)
	{
		ans=2*sqrt(double(ans*a[i]));
	}
	printf("%.3lf\n",ans);
	return 0;
}