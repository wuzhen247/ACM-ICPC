#include<iostream>
using namespace std;
int main()
{
	int n,a,b,s,d;
	cin>>n;
	while(n--)
	{
		cin>>s>>d;
		if(s<d)
		  cout<<"impossible\n";
		else if((s-d)%2!=0)
		  cout<<"impossible\n";
		else
		  cout<<(s+d)/2<<' '<<(s-d)/2<<endl;
	}
	return 0;
}
		
