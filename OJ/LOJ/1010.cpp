#include<iostream>
using namespace std;
int main()
{
	int a[4],m,n,x,y;
	while(cin>>m>>n>>a[0]>>a[1]>>a[2]>>a[3])
	{
		x=a[2]-a[0];
		y=a[3]-a[1];
		x=x>0?x:-x;
		y=y>0?y:-y;
		if(x==y)
		{
			cout<<"hinder"<<endl;
		}
		else
		{
			cout<<"former"<<endl;
		}
	}
	return 1;
}