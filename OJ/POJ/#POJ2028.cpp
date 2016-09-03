//n个人开会，条件至少q个人有空，求符合条件人数最多那天的最早时间 
#include<iostream>
#include<cstring>
using namespace std;
int a[110],n,q;
int main()
{
	int num,i,j,temp,pepole,date;
	while(cin>>n>>q,n||q)
	{
		memset(a,0,sizeof(a));
		
		for(i=0;i<n;i++)
		{	
			cin>>num;
			while(num--)
			{
				cin>>temp;
				a[temp]++;          //将时间做下标，内容为有空人数 
			}
		}
		
		pepole=0;
		date=0;
		for(j=1;j<101;j++)
		{
			if(a[j]>=q&&pepole<a[j])
			{
				date=j;
				pepole=a[j];
			}
		}
		cout<<date<<endl;
	}
	return 0;
}

				


