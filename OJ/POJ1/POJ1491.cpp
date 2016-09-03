#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n,a[55],i,j,sum;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		  scanf("%d",&a[i]);
		sum=0;
		for(i=0;i<n;i++)
		{
		  for(j=i+1;j<n;j++)
		  {
			if(gcd(a[i],a[j])==1)
			{
			  sum++;
			}
		  }
		}
		if(sum==0)
		  printf("No estimate for this data set.\n");
		else
		  printf("%f\n",sqrt(6/(sum/(n*(n-1)/2.0))));
	}
	return 0;
}
