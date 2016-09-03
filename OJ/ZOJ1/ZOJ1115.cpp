#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int i,len,sum,n;
	while(cin>>s&&s[0]!='0')
	{
		len=s.length();
		sum=0;
		for(i=0;i<len;i++)
			sum+=s[i]-'0';
		n=sum;
		while(sum>9)
		{
			sum=0;
			while(n>0)
			{
				sum+=n%10;
				n/=10;
			}
			n=sum;
		}
		cout<<sum<<endl;
	}
	return 0;
}
