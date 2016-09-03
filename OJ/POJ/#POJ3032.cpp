#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[200],b[14];
int main()
{
	int i,j,t,k,n,front,rear;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(k=1;k<=n;k++)
			b[k]=k;
		front=1,rear=2;
		a[front]=b[n];
		for(i=n-1;i>=1;i--)
		{
			a[rear++]=b[i];
			for(j=1;j<=i;j++)
			{
				a[rear++]=a[front++];
			}
		}
		for(rear--;rear>=front;rear--)
			cout<<a[rear]<<' ';
		cout<<endl;
	}
	return 0;
}
