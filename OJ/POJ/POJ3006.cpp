#include<cstdio>
#include<cstring>
#include<iostream>
#define N 1000005
using namespace std;
bool b[N]={false};
void prime()
{
	int i,j;
	b[0]=b[1]=true;
	for(i=2;i<=N;i++)
	{
		for(j=i+i;j<=N;j+=i)
			b[j]=true;
	}
}
int main()
{
	int a,d,n,i,num;
	prime();
	while(scanf("%d%d%d",&a,&d,&n)&&(a||d||n))
	{
		num=0;
		for(i=a;num<n;i+=d)
		{
			if(b[i]==false)
				num++;
		}
		cout<<i-d<<endl;
	}
	return 0;
}
