//将循环小数化为准确分数
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	char s[100];
	int sum,k,mina,minb,a,b,l,num,i,j;
	while(scanf("%s",s)&&strcmp(s,"0"))
	{
		mina=minb=1<<31-1;
		for(l=0,sum=0,i=2;s[i]!='.';i++)
		{
			sum=sum*10+s[i]-48;
			l++;
		}
		for(num=sum,k=1,i=1;i<=l;i++)
		{
			num/=10;
			k*=10;
			a=sum-num;
			b=(int)pow(10.0,l-i)*(k-1);
			j=gcd(a,b);
			if(b/j<minb)
			{
				mina=a/j;
				minb=b/j;
			}
		}
		printf("%d/%d\n",mina,minb);
	}
	return 0;
}
