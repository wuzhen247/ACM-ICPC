#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int f1(int a)
{
	while(a%10==0) { a/=10;}
	return a;
}
int f2(int a)
{
	int b=0;
	while(a)
	{
		b=b*10+a%10;
		a/=10;
	}
	return b;
}
		  
int main()
{
	int n,i,j,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		a=f1(a),b=f1(b);
		a=f2(a),b=f2(b);
		a+=b;
		a=f2(a);
		printf("%d\n",a);
	}
	return 0;
}
