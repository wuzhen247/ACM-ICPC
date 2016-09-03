//整数划分，单峰
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 305

int main()
{
	int i,j,n;
	__int64 s[N][N];
	memset(s,0,sizeof(s));
	for(i=0;i<N;i++)
	  s[0][i]=1;
	for(i=1;i<N;i++)
	  for(j=i/2+1;j<=i;j++)
		s[i][j]=1;
	for(i=2;i<N;i++)
	  for(j=i/2;j>0;j--)
		s[i][j]=s[i-2*j][j]+s[i][j+1];
	while(scanf("%d",&n)&&n)
	  printf("%d %I64d\n",n,s[n][1]);
	return 0;
}
