#include<iostream>
#include<cstdio>
using namespace std;
int T[305];
int main()
{
	int N,n,i,t,ans;
	for(i=1;i<305;i++)
	  T[i]=i*(i+1)/2;
	scanf("%d",&N);
	for(t=1;t<=N;t++)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
			ans+=i*T[i+1];
		printf("%d %d %d\n",t,n,ans);
	}
	return 0;
}
