#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,a[102][102],s[102];
int MAX(void)
{
	int i,max=s[1],temp=s[1];
	for(i=2;i<=n;i++)
	{
		if(temp<0)
		  temp=s[i];
		else
		  temp+=s[i];
		if(max<temp)
		  max=temp;
	}
	return max;
}
int main()
{
	int i,j,r,k,max=-(1<<30),temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			memset(s,0,sizeof(s));
			for(r=i;r<=j;r++)
			  for(k=1;k<=n;k++)
				s[k]+=a[r][k];
			temp=MAX();
			if(temp>max)
			  max=temp;
		}
	printf("%d\n",max);
	return 0;
}

