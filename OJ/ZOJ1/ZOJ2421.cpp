#include<iostream>
#include<cstdio>
#include<cstring>
int a[500002];
bool f[40000020];
int main()
{
	int n,i;
	memset(f,false,sizeof(f));
	a[0]=0,f[0]=true;
	for(i=1;i<500001;i++)
	{
		a[i]=a[i-1]-i;
		if(a[i]<0||f[a[i]]==true)
		  a[i]=a[i-1]+i;
		f[a[i]]=true;
	}
	while(scanf("%d",&n)&&n!=-1)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}
