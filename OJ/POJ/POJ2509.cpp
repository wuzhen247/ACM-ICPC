#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,k,sum,i,j,temp1,temp2;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		temp1=n/k;
		sum=n;
		while(temp1)
		{
			sum+=temp1;
			temp2=n%k;
			n=temp1+temp2;
			temp1=n/k;
		}
		cout<<sum<<endl;
	}
	return 0;
}
		
