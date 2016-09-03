#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1005];
float ave,ans;
int num,sum;

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		num=sum=0;
		for(i=0;i<n;i++)
		{
		  scanf("%d",&a[i]);
		  sum+=a[i];
		}
		ave=float(sum)/n;
		for(i=0;i<n;i++)
		{
			if(a[i]>ave)
			  num++;
		}
		ans=float(num)/n*100;
		printf("%.3f%%\n",ans);
	}
	return 0;
}


