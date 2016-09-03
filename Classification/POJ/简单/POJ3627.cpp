//求最少的人让他们的高度超过一个数字
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[20005];

int main()
{
	int n,b,i,ans;
	scanf("%d%d",&n,&b);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	ans=0;
	for(i=n-1;i>=0;i--)
	{
		if(b<=0)
			break;
		b-=a[i];
		ans++;
	}
	printf("%d\n",ans );
	return 0;
}