//����11111�ġ�����11��Ϊn�ı�������Сλ��
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,i,num,sum,a;
	while(scanf("%d",&n)!=EOF)
	{
		num=1,sum=1,a=1;
		while(sum%n!=0)
		{
			a*=10;
			num++;
			a%=n;
			sum+=a;
		}
		printf("%d\n",num);
	}
	return 0;
}
