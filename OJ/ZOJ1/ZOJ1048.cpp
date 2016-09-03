#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	float sum=0,ave=0,m;
	while(scanf("%f",&m)!=EOF)
	{
		sum+=m;
	}
	ave=sum/12.0;
	printf("$%.2f",ave);
	return 0;
}

