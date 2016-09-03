//已知钉个数和半径，计算绳子长度
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	float a[105],b[105],r;
	int n,i,k;
	while(scanf("%d%f",&n,&r)==2)
	{
		double len=0;
		for(k=0;k<n;k++)
			scanf("%f%f",a+k,b+k);
		len+=sqrt((a[n-1]-a[0])*(a[n-1]-a[0])+(b[n-1]-b[0])*(b[n-1]-b[0]));
		for(i=0;i<n-1;i++)
			len+=sqrt((a[i+1]-a[i])*(a[i+1]-a[i])+(b[i+1]-b[i])*(b[i+1]-b[i]));
		len+=2*3.1415926*r;
		printf("%.2lf\n",len);
	}
	return 0;
}
