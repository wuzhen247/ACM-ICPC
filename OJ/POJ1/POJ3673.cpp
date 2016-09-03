#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char a[20],b[20];
	int n1,n2,i,j,sum;
	scanf("%s%s",a,b);
	n1=n2=sum=0;
	n1=strlen(a);
	n2=strlen(b);
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
			sum+=(a[i]-'0')*(b[j]-'0');
	}
	printf("%d\n",sum);
	return 0;
}
