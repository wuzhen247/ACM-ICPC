/*�ڽ�������n���Farmer Johnÿ����Ҫ��money[i]Ǯ������Щ��ֳ�m�ݣ�ÿ�ݶ����������죩��Ҫ��ÿ�ݵĺ;����٣���������С�ĺ͡�
 
˼·��̰�ĵ�˼�룬�ö���ȥ�������Ӷ�ΪO(nlogM)��M = sum - max����ʼ״̬���Ͻ�highΪn�컨�ѵ��ܺ�sum���½�Ϊÿ�컨�ѵ����ֵmax��Ȼ����֣�ÿ�ε�midֵΪ��low+high��/ 2��Ȼ�����midֵ������ֵ������n�컨�ѣ��������midֵ�ܰ�n��ֳɼ��ݣ������������m����ʾmidƫС��low = mid + 1����֮high = mid - 1��*/

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
