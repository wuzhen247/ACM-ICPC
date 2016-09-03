/*给定n个二元组(a,b)，扔掉k个二元组，使得剩下的   最大。

　　这两天一直在搞分数规划，有了前两道题（3621、2728），这道题就是完完全全的大水题了。

　　设 r=100*∑(ai)/∑(bi) ，有

　　　　100*∑(ai)-r*∑(bi)=0

　　　　∑(100*ai-r*bi)=0

　　这个东西是单调的……

　　我们可以将每个二元组的得分设为100*a-r*b，然后从大到小排序，取前n-k个得分求和(sum)。若sum>0则说明r还不够大，可以向上二分；反之向下二分……
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
