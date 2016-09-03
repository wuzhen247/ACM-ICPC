#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int m,p,a,b,x,y,re,i;
	double temp,temp1,temp2,temp3;
	while(scanf("%d%d%d%d",&m,&p,&a,&b)!=EOF)
	{
		temp=(m+a*b)/(a+1.0);
		x=floor(temp),y=m-ceil(temp);
		temp=(b-x)*sqrt(a)+y/sqrt(a);
		for(i=1,temp1=1,temp2=1;i<=p/2;i++)
		{
		  temp1*=a;
		  temp2*=1.0/a;
		}
		for(i=1,temp3=1;i<=p;i++)
		  temp3*=temp;
		re=x*temp1+y*temp2+temp3+0.5;
		printf("%d\n",re);
	}
	return 0;
}


		
