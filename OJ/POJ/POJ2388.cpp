#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[10005],i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",a+i);
	sort(a+1,a+n+1);
	printf("%d\n",a[(n+1)/2]);
	return 0;
}
