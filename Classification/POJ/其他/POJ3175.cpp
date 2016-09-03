//给一个字符串，求那个整数的开方的小数部分前n个有效数位即该字符串(精度问题)
#include<cstring>
#include<cstdio>
using namespace std;

double pow_1[] = { 1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10 };  

int main()
{
	double i,j,b,p;
	int l,d;
	scanf("%d%d",&l,&d);
	p=pow_1[l];
	b=p*d;
	for(int k=1;;k++)
	{
		i=(__int64)((k+b)*(k+b))+1;
		j=(k+b+p)*(k+b+p);
		if(j>i)
		  break;
	}
	printf("%lld\n",(__int64)i);
}
			
