#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500005
using namespace std;
bool f[5000000];
int a[N];
int main()
{
	int k,i;
	memset(f,false,sizeof(f));
	a[0]=0,f[0]=true;
	for(i=1;i<N;i++)
	{
		if(a[i-1]-i>0&&f[a[i-1]-i]==false)
		  a[i]=a[i-1]-i;
		else
		  a[i]=a[i-1]+i;
		f[a[i]]=true;
	}
	while(scanf("%d",&k)&&k!=-1)
	{
		printf("%d\n",a[k]);
	}
	return 0;
}

