//Paint Mix,黑白瓶相互倒至一定比例，求倾倒次数
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define eps 0.00001

int main()
{
	double b,w,c,ans,rateb,ratew;
	int n;
	while(scanf("%lf%lf%lf",&b,&w,&c)&&(b||w||c))
	{
		b*=16,w*=16;
		ans=b/w;
		n=0;
		ratew=0,rateb=1;
		while(fabs(ratew/(1-ratew)-ans)>eps||fabs(rateb/(1-rateb)-ans)>eps)
		{
			ratew=1-(w*(1-ratew)+c*(1-rateb))/(c+w);
			rateb=((b-c)*rateb+c*ratew)/b;
			n++;
		}
		printf("%d\n",n);
	}
	return 0;
}
