#include<iostream>
using namespace std;
int main()
{
	int t,a[100],b[20];
	b[0]=1;
	b[1]=2;
	for(int i=2;i<20;i++)
	{
		b[i]=b[i-1]+b[i-2];
	}
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>a[j]; 
	}
	for(int k=0;k<t;k++)
	{
		cout<<b[a[k]-1]<<endl;
	}
	return 0;
}
