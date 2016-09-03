#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,j,num=1;
	char s[16][28];
	while(cin>>n&&n!=0)
	{
		getchar();
		for(i=0;i<n;i++)
			gets(s[i]);
	
//		for(i=0;i<n;i++)
//			cout<<s[i]<<endl;
		cout<<"SET "<<num++<<endl;
		if(n%2==0)
		{
			for(j=0;j<=n-2;j+=2)
			{
				cout<<s[j]<<endl;
			}
			for(j=n-1;j>=1;j-=2)
			{
				cout<<s[j]<<endl;
			}
		}
		else
		{
			for(j=0;j<=n-1;j+=2)
				cout<<s[j]<<endl;
			for(j=n-2;j>=0;j-=2)
			{
				cout<<s[j]<<endl;
			}
		}
	}
	return 0;
}	
