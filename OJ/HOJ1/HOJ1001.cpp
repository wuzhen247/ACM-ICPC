#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long n;
	while(scanf("%ld",&n)!=EOF)
	{
		printf("%ld\n\n",n%2==0?n/2*(n+1):(n+1)/2*n);
	}
	return 0;
}
