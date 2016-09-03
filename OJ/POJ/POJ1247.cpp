#include<iostream>
using namespace std;
//#define A "Sam stops at position";
//#define B "Ella stops at position";
//#define C "NO equal partitioning.";
int main()
{
	int n,i,j,a[32],sum1,sum2,temp,temps,tempe;
	while(cin>>n&&n!=0)
	{
		sum1=0,sum2=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		temp=n/2;
		for(i=1;i<temp;i++)
		{
			sum1+=a[i];
		}
		for(;i<=n;i++)
		{
			sum2+=a[i];
		}
		if(sum1==sum2)
		{
			temps=temp-1;
			tempe=temp;
		}
		else if(sum1>sum2)
		{
			while(sum1>sum2)
			{
				temp--;
				sum1-=a[temp];
				sum2+=a[temp];
			}
			if(sum1==sum2)
			{
				temps=temp-1;
				tempe=temp;
			}
			else
			{
				cout<<"No equal partitioning."<<endl;
	//			cout<<C;
	//			cout<<endl;
				continue;
			}
		}
		while(sum1<sum2)
		{
			sum1+=a[temp];
			sum2-=a[temp];
			temp++;
		}
		if(sum1==sum2)
		{
			temps=temp-1;
			tempe=temp;
		}
		else
		{
			cout<<"No equal partitioning."<<endl;
	//		cout<<C;
	//		cout<<endl;
			continue;
		}
		cout<<"Sam stops at position "<<temps<<" and Ella stops at position "<<tempe<<"."<<endl;
//		cout<<A;
//		cout<<' '<<temps<<" and "<<B;
//		cout<<' '<<tempe<<'.'<<endl;
	}
	return 0;
}


				
		

		
	
		
