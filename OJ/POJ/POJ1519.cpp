#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,y,i;
	char a[50000];
	while(1)
	{
		cin.getline(a,50000);
		if(a[0]=='0')
			return 0;
		y=0;
		n=0;
		for(i=0;a[i]!=0;i++);
		for(;i;)
		{
			y+=a[--i]-'0';
		} 
		n=y;
		y=0;
		while(n)
		{
			y+=n%10;
			n/=10;
		}
		n=y;
		while(y/10)
		{
			y=0;
			while(n)
			{
				y+=n%10;
				n/=10;
			}
			n=y;
		}
		cout<<y<<endl;
	}
	return 0;
}
