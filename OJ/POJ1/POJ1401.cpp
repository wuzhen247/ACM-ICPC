//����n��ĩβ0�ĸ���
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	int t,n,num,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		p=5;
		num=0;
		while((n/p)>=1)
		{
			num+=n/p;
			p*=5;
		}
		printf("%d\n",num);
	}
	return 0;
}
		
