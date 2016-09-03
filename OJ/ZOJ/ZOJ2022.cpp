#include<iostream>
using namespace std;
int main()
{
	int n,x,j,y;
	cin>>n;
	while(n--)
	{
		cin>>x;
		y=0;
		while(x>=5)
		{
		 	x=x/5;
			y+=x;		
		}
		cout<<y<<endl;
	}	
	return 0;
}



