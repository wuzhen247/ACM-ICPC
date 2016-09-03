#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,n1,n2,n3,sum1,sum2,sum3;
	for(i=2992;i<10000;i++)
	{
		sum1=sum2=sum3=0;
		n1=n2=n3=i;
		while(n1>0)
		{
			sum1+=n1%10;
			n1/=10;
		}
		while(n2>0)
		{
			sum2+=n2%12;
			n2/=12;
		}
		while(n3>0)
		{
			sum3+=n3%16;
			n3/=16;
		}
		if(sum1==sum2&&sum2==sum3)
		  printf("%d\n",i);
	}
	return 0;
}

