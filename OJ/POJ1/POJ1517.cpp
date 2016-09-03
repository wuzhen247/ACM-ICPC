//Çóe
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	printf("n e\n- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	int a[10],i;
	a[2]=2;
	double s=2.5;
	for(i=3;i<10;i++)
	{
		a[i]=a[i-1]*i;
		printf("%d %.9llf\n",i,s=s+1.0/a[i]);
	}
	return 0;
}
