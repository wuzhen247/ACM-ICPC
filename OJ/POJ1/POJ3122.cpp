//����n��pie��ֱ������f+1���ˣ������ÿ�˷ֵĴ�С��ͬ����״���Բ�ͬ����ÿ���˿��Էֶ��١�Ҫ���Ƿֳ�����ÿһ�ݱ������ͬһ��pie��Ҳ����˵��pie��С//Ϊ3��2��1��ֻ�ֳܷ�������СΪ2�ķݣ�ʣ������Ҫ�ӵ����������ж���ģ�
//����+̰��
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
