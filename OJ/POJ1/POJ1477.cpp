#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[55],n,ave,num,i,j,sum;
	j=0;
	while(scanf("%d",&n)&&n)
	{
		sum=num=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		ave=sum/n;
		for(i=0;i<n;i++)
		{
			if(a[i]<ave)
				num+=ave-a[i];
		}
		j++;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,num);
	}
	return 0;
}

