#include<iostream>
using namespace std;
int main()
{
	int a[8][2];
	int n,i,j,max,index,temp;
	while(cin>>n&&n!=0)
	{
		max=0,index=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
				cin>>a[i][j];
			if((temp=a[i][0]+a[i][1])>8&&temp>max)
			{
				max=temp;
				index=i+1;
			}
		}
		cout<<index<<endl;
	}
	return 0;
}
