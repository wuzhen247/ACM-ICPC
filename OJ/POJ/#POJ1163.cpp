//求三角阵路径权值和最大 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105][105],b[105][105];
int search(int i,int j)
{
	int sum,f1,f2;
	if(i==0)
		return a[0][0];
	if(j==0)
	{
		sum=0;
		if(b[i-1][0]!=0)
			return b[i][0]=a[i][0]+b[i-1][0];
		for(int k=0;k<=i;k++)
			sum+=a[k][0];
		return sum;
	}
	if(j==i)
	{
		sum=0;
		if(b[i-1][i-1]!=0)
			sum=a[i][i]+b[i-1][i-1];
		else
			for(int k=0;k<=i;k++)
				sum+=a[k][k];
		return b[i][i]=sum;
	}
	if(b[i-1][j]!=0)
		f1=b[i-1][j];
	else
		f1=search(i-1,j);
	if(b[i-1][j-1]!=0)
		f2=b[i-1][j-1];
	else
		f2=search(i-1,j-1);
	if(f1>f2)
		return b[i][j]=a[i][j]+f1;
	else
		return b[i][j]=a[i][j]+f2;
}
int main()
{
	int n,i,j,max,temp;
	cin>>n;
	max=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			cin>>a[i][j];
		}
	}
	for(j=0;j<n;j++)
	{
		temp=search(n-1,j);
		if(temp>max)
			max=temp;
	}
	cout<<max<<endl;
}

	
