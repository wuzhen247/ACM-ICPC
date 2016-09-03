#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	float x,y,s,pi=acos(-1);
	int i,t,temp;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%f %f",&x,&y);
		s=pi*(x*x+y*y);
		temp=s/100;
		printf("Property %d: This property will begin eroding in year %d.\n",i,temp+1);
	}
	printf("END OF OUTPUT.\n"); 
	return 0;
}
