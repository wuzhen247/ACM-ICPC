#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000001
int a[N],b[N];
int main()
{
	int n,k,d,i,j,temp,min,index,m;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		temp=2*n*k;
		for(i=0;i<temp;i++)
			scanf("%d",&a[i]);
		sort(a,a+temp);
		for(i=0;i<temp-1;i++)
			b[i]=a[i+1]-a[i];
		d=b[0],index=0;
		while(--n)
		{
			j=index+1;
			min=b[j];
			j++;
			for(m=1;m<2*k;m++,j++)
			{
				if(b[j]<min)
				{
					min=b[j];
					index=j;
				}
			}
			if(min>d)
				d=min;	
		}
		printf("%d\n",d);	
	}
	return 0;
}
