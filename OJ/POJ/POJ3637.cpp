#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,a[20100],i,j,k,discount;
	cin>>t;
	for(i=0;i<t;i++)
	{
		discount=0;
		cin>>n;
		for(j=0;j<n;j++)
			cin>>a[j];
		sort(a,a+n);
		for(j=n-1;j>=2;j-=3)
			discount+=a[j-2];
		cout<<discount<<endl;
	}
	return 0;
}


