#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int a[1000000];
int main()
{
	int m,k,i,j;
	while(cin>>m>>k)
	{
		for(i=1,j=0;i<=m;i++)
		{
			if(gcd(m,i)==1)
			  a[++j]=i;	  
		}
		if(k%j==0)
		  cout<<(k/j-1)*m+a[j]<<endl;
		else
		  cout<<k/j*m+a[k%j]<<endl;
	}
	return 0;
}
		
