//求严格递增子序列长度
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1005],b[1005];
int main()
{
	int n,i,j,s;
	memset(b,0,sizeof(b));
	s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	  for(j=0;j<i;j++)
		if(a[j]<a[i]&&b[i]<=b[j])
		  b[i]=b[j]+1;
	s=0;
	for(i=0;i<n;i++)
	  if(b[i]>s)
		s=b[i];
	printf("%d\n",s+1);
	return 0;
}
