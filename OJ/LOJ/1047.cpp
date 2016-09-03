#include<iostream>
using namespace std;
int eular(int n)
{
int ret=1,i;
for(i=2;i*i<=n;i++)
if(n%i==0)
{
n/=i,ret*=i-1;
while(n%i==0)
n/=i,ret*=i;
}
if(n>1)
ret*=n-1;
return ret;
}
int main()
{
	int i,j,a[100001];
	long int f;
	for(int k=1;k<=100000;k++)
	{
		a[k]=eular(k);
	}
	while(cin>>i>>j)
	{
		f=1;
		for(int x=i;x<=j;x++)
		{
			f*=a[x];
			if(f>99991)
			{
				f%=99991;
			}
		}
		cout<<f<<endl;
	}
	return 1;
}
