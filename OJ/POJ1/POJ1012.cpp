#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int k,m,n,i,a[30],b[15]={0};
	while(scanf("%d",&k)&&k!=0)
	{
		if(b[k]!=0)
		{
			cout<<b[k]<<endl;
			continue;
		}
		n=2*k;
		m=1;
		for(i=1,a[0]=0;i<=k;i++)
		{
			a[i]=(a[i-1]+m-1)%(n-i+1);
			if(a[i]<k)
			{
				i=0,m++;
			}
		}
		b[k]=m;
		cout<<m<<endl;
	}
	return 0;
}
