#include<iostream>
using namespace std;
int main()
{
	int n,i,a[12],b[12],sum;
	while(cin>>n&&n!=-1)
	{
		for(i=0;i<n;i++)
			cin>>a[i]>>b[i];
		sum=a[0]*b[0];
		for(i=1;i<n;i++)
		{
			sum+=a[i]*(b[i]-b[i-1]);
		}
		cout<<sum<<" miles\n";
	}
	return 0;
}

