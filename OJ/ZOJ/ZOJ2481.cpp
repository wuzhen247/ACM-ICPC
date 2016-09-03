#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	int n,i,j,temp;
	int a[101];
	while(cin>>n&&n!=0)
	{
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		//sort(a,a+n);
		temp=a[0];
		cout<<a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]==temp)
			{
				continue;
			}
			cout<<' '<<a[i];
			temp=a[i];
		}
		cout<<endl;
	}
	return 0;
}
			

