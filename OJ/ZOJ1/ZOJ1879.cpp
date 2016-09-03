#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a[3005],b[3005];
int main()
{
	int t,i,n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(b,0,sizeof(b));
		scanf("%d",&a[0]);
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			t=abs(a[i]-a[i-1]);
			b[t]++;
		}
		for(i=1;i<n;i++)
		{
			if(b[i]!=1)
			{
				printf("Not jolly\n");
				break;
			}
		}
		if(i==n)
		  printf("Jolly\n");
	}
	return 0;
}
