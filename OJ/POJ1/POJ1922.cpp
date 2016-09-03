#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,t,b;
	double a,tm,min;
	while(scanf("%d",&n)&&n)
	{
		min=344443443.0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%d",&a,&b);
			if(b<0) continue;
			tm=4.5*3600*1.0/a+b*1.00;
			if(min>tm)
			  min=tm;
		}
		t=min;
		if(min-t!=0)
		  printf("%.f\n",min+0.5);
		else
		  printf("%d\n",t);
	}
	return 0;
}

