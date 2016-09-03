#include<iostream>
using namespace std;
int main()
{
	int n,y,i;
	while(cin>>n)
	{
		y=1;
		for(i=1;i<n;i++)
		{
			y=2*(y+1);
		}
		cout<<y<<endl;
	}
	return 0;
}

