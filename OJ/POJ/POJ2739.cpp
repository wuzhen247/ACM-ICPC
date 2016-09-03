#include<iostream>
using namespace std;
int a[10010]={0};
bool isprime(int n)
{
	if(n==2||n==3||n==5||n==7)
		return true;
	if(n%2==0||n==1)
		return false;
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	int n,temp,num,i,j;
	a[0]=2;
	for(i=1,j=3;j<10000;j+=2)
	{
		if(isprime(j))
		{
			a[i]=j;
			i++;
		}
	}
	while(cin>>n&&n!=0)
	{
		num=0;
		if(isprime(n))
			num++;
		for(i=0;a[i]<n;i++)
		{
			temp=0;
			for(j=i;temp<n;j++)
				temp+=a[j];
			if(temp==n)
				num++;
		}
		cout<<num<<endl;
	}
	return 0;
}


