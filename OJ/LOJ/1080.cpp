#include <iostream>
using namespace std;
int main()
{
	int a[100][3];
	int n;
	while(cin>>n)
	{
		for(int i;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][0]+a[i][1]>a[i][2]&&a[i][1]+a[i][2]>a[i][0]&&a[i][0]+a[i][2]>a[i][1])
				cout<<'Y'<<endl;
			else
				cout<<'N'<<endl;
		}

	}
	return 1;
}
