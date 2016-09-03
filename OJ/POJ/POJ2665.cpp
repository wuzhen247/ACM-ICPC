#include<iostream>
using namespace std;
int main()
{
	int l,m,a[5010][2],sum,i,j;
	while(cin>>l>>m)
	{
		sum=0;
		if(l==0&&m==0)
			break;
		for(i=0;i<m;i++)
		{
			for(j=0;j<2;j++)
			{
				cin>>a[i][j];
			}
			sum+=a[i][1]-a[i][0]+1;
		}
		cout<<l-sum+1<<endl;
	}
	return 0;
}

		
