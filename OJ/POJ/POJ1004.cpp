#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	double temp,sum;
	int i;
	sum=0;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&temp);
		sum+=temp;
	}
	sum/=12;
	sum=sum*100+0.5;
	i=(int)sum;
	sum=i/100.0;
	cout<<'$'<<sum<<endl;
	return 0;
}

