//给出n个pie的直径，有f+1个人，如果给每人分的大小相同（形状可以不同），每个人可以分多少。要求是分出来的每一份必须出自同一个pie，也就是说当pie大小//为3，2，1，只能分出两个大小为2的份，剩下两个要扔掉。（可以有多余的）
//二分+贪心
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-6;
double r[10005];

int main()
{
	int n,f,t,i,num;
	double sum,low,high,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&f);
		f++;
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%lf",&r[i]);
			r[i]*=r[i];
			sum+=r[i];
		}
		high=sum/f;
		low=0;
		while(high-low>eps)
		{
			mid=(low+high)/2;
			num=0;
			for(i=0;i<n;i++)
				num+=int(r[i]/mid);
			if(num>=f)	low=mid;
			else		high=mid;
		}
		printf("%.4lf\n",mid*pi);
	}
	return 0;
}
