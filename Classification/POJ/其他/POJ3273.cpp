/*在接下来的n天里，Farmer John每天需要花money[i]钱，把这些天分成m份（每份都是连续的天），要求每份的和尽量少，输出这个最小的和。
 
思路：贪心的思想，用二分去做，复杂度为O(nlogM)，M = sum - max。初始状态，上界high为n天花费的总和sum，下界为每天花费的最大值max。然后二分，每次的mid值为（low+high）/ 2，然后根据mid值（估计值）遍历n天花费，看看这个mid值能把n天分成几份，如果份数大于m，表示mid偏小，low = mid + 1，反之high = mid - 1。*/

#include<iostream>
#include<cstdio>

int n,m,a[100050];

int main()
{
	int mid,high,low,i,sum,max,num,tm;
	scanf("%d%d",&n,&m);
	for(i=0,max=0,sum=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>max)
		  max=a[i];
	}
	low=max,high=sum;
	while(low<high)
	{
		mid=(low+high)/2;
		num=1,tm=0;
		for(i=0;i<n;i++)
		{
			tm+=a[i];
			if(tm>mid)
			{
				num++;
				tm=a[i];
			}
		}
		if(num<=m)	high=mid-1;
		else		low=mid+1;
	}
	printf("%d\n",high);
	return 0;
}
