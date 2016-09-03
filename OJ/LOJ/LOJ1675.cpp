#include<iostream>
using namespace std;
int main()
{
	int n,k,i,j,temp;
	while(cin>>n)
	{
		n=n>0?n:-n;
		temp=0;
		for(k=0;temp<n;)
		{
			k++;
			temp=k*(k+1)/2;
		}
		if(temp==n)
		{
			cout<<k<<endl;
			continue;
		}
		if((temp%2-n%2)==0)
		{
			cout<<k<<endl;
		}
		else 
		{
			temp=(k+1)*(k+2)/2;
			if((temp%2-n%2)==0)
			{
				cout<<k+1<<endl;
				continue;
			}
			else
			{
				cout<<k+2<<endl;
				continue;
			}
		}
	}
	return 0;
}
