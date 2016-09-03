#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,n,i,j,temp1,temp2=0,a[22],num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		temp2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp1);
			a[i]=temp1-temp2;
			temp2=temp1;
			num=1;
			for(j=i;j>=0;j--)
			{
				if(a[j]>0)
				{
					a[j]--;
					break;
				}
				else
				  num++;
			}
			printf("%d ",num);
		}
		printf("\n");
	}
	return 0;
}

