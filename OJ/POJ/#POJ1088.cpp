#include<iostream>
#include<cstring> 
using namespace std;
int b[102][102]={0},a[102][102]={0},c,d;
int len(int i,int j)
{
	if (b[i][j]>0)
		return b[i][j];
	int temp=0;
	if(a[i-1][j]>a[i][j])
	{
		b[i-1][j]=len(i-1,j);
		if(b[i-1][j]>temp)
			temp=b[i-1][j];
	}
	if(a[i+1][j]>a[i][j])
	{
		b[i+1][j]=len(i+1,j);
		if(b[i+1][j]>temp)
			temp=b[i+1][j];
	}
	if(a[i][j-1]>a[i][j])
	{
		b[i][j-1]=len(i,j-1);
		if(b[i][j-1]>temp)
			temp=b[i][j-1];
	}
	if(a[i][j+1]>a[i][j])
	{
		b[i][j+1]=len(i,j+1);
		if(b[i][j+1]>temp)
			temp=b[i][j+1]; 
	}
	return b[i][j]=1+temp;
}
int main()
{
	int r,c,i,j,max=0,temp;
	while(cin>>r>>c)
	{
		max=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			temp=len(i,j);
			if(temp>max)
			{
				max=temp;
			}	
		}
	}
	cout<<max<<endl;
	} 
	return 0;
}


