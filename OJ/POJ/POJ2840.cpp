#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[8];
	int i,j,n,s;
	cin>>n;
	getchar();
	for(i=0;i<n;i++)
	{
		s=0;
		gets(a);
		for(j=0;a[j]!=':';j++);
		if(a[j+1]!='0')
		{
			cout<<0<<endl;
			continue;
		}
		if(a[j+2]!=0&&a[j+2]!='0')
		{
			cout<<0<<endl;
			continue;
		}
		if(j==1)
			s=a[j-1]-'0';
		else
			s=a[j-1]-'0'+(a[j-2]-'0')*10;
		if(s==0)
		{
			cout<<12<<endl;
			continue;
		}
		if(s>12)
			cout<<s-12<<endl;
		else
			cout<<s+12<<endl;
	}
	return 0;
}
