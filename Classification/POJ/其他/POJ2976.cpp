/*����n����Ԫ��(a,b)���ӵ�k����Ԫ�飬ʹ��ʣ�µ�   ���

����������һֱ�ڸ�����滮������ǰ�����⣨3621��2728����������������ȫȫ�Ĵ�ˮ���ˡ�

������ r=100*��(ai)/��(bi) ����

��������100*��(ai)-r*��(bi)=0

����������(100*ai-r*bi)=0

������������ǵ����ġ���

�������ǿ��Խ�ÿ����Ԫ��ĵ÷���Ϊ100*a-r*b��Ȼ��Ӵ�С����ȡǰn-k���÷����(sum)����sum>0��˵��r�������󣬿������϶��֣���֮���¶��֡���
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define eps 1e-4
using namespace std;

int a[1005],b[1005],n,k;
double f[1005];

bool cmp(double a,double b)
{
	return a>b;
}

int main()
{
	int i;
	double sum,high,mid,low;
	while(scanf("%d%d",&n,&k)&&(n||k))
	{
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		for(i=0;i<n;i++)	scanf("%d",&b[i]);
		high=100,low=0;
		while(high-low>eps)
		{
			mid=(low+high)/2.0;
			for(i=0;i<n;i++)	
			  f[i]=100.0*a[i]-mid*b[i];
			sort(f,f+n,cmp);
			sum=0;
			for(i=0;i<n-k;i++)	
			  sum+=f[i];
			if(sum>0)	low=mid;
			else	high=mid;
		}
		printf("%d\n",int(low+0.5));
	}
	return 0;
}
