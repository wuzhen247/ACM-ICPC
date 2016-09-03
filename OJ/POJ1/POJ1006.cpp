#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,c,d,temp,num=1;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)&&(!(a==-1&&b==-1&&c==-1&&d==-1)))
	{
		temp=(5544*a+14421*b+1288*c-d+21252)%21252;
		if(temp==0)
		  temp=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",num,temp);
		num++;
	}
	return 0;
}
