//��һ���ַ��������Ǹ������Ŀ�����С������ǰn����Ч��λ�����ַ���(��������)
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
			
