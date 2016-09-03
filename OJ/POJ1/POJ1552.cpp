#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[18],n;
int main()
{
	int i,num,j;
	while(scanf("%d",&a[0])&&a[0]!=-1)
	{
		num=0;
		for(n=1;;n++)
		{
			scanf("%d",&a[n]);
			if(a[n]==0)
			  break;
		}
		sort(a,a+n);
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			  if(a[i]/a[j]==2&&a[i]%a[j]==0)
				num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
