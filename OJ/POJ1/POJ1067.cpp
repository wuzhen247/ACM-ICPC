#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a, b, k, temp;
	while (scanf("%d%d",&a,&b) != EOF)
	{
		if (a < b)
		  swap(a,b);
		temp = a - b;
		k = (floor)(temp*(1.0+sqrt(5))/2.0);
		if(k == b)
		  printf("0\n");
		else
		  printf("1\n");
	}
	return 0;
}
