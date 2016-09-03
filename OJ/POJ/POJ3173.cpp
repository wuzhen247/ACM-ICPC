#include<iostream>
using namespace std;
int main()
{
	int a[50][50]={0},i,j,n,s,k;
	cin>>n>>s;
	for(j=0;j<n;j++)
		for(i=0;i<=j;i++)
		{
			a[i][j]=s++;
			if(s>9)
				s=1;
		}
	for(i=0;i<n;i++)
	{
		for(k=0;k<2*i;k++)
			cout<<' ';
		for(j=i;j<n;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}


