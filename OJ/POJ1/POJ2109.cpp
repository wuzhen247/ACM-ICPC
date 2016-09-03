#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n,p;
	while(cin>>p>>n)
	{
		cout<<pow(n,1.0/p)<<endl;
	}
	return 0;
}
