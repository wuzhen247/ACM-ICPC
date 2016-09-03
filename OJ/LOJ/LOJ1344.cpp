#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,j;
	char a[3000][101]={0};
	int c[3000]={0};
	while(cin>>n)
	{
		getchar();
		for(i=1;i<3*n+1;i++)
		{
			gets(a[i]);
			if(i%3==0&&i!=3*n)
			{
				getchar();
			}
		}
	/*	for(i=1;i<=3*n;i++)
		{
			cout<<a[i]<<endl;
			
		}*/
	
		for(i=1;i<=3*n;i++)
		{
			for(j=0;a[i][j]!=0;j++)
			{
				if(a[i][j]=='a'||a[i][j]=='e'||a[i][j]=='i'||a[i][j]=='o'||a[i][j]=='u')
				{
					c[i]++;
				}
			}
		}
		for(i=1;i<=3*n;i+=3)
		{
			if(c[i]==9&&c[i+1]==9&&c[i+2]==6)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
} 
