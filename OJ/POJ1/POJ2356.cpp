#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10005

int ans[N],used[N];

int main()
{
	int n,i,j,k;
	bool f;
	scanf( "%d",&n );
	memset(used,-1,sizeof(used));
	for(i=1; i<=n; i++)
		scanf("%d",&ans[i]);

	f = false;
	used[0] = 0;
	k=0;
	for(i=1; i<=n; i++)
	{
		k = (k+ans[i]) % n;
		if(used[k] !=-1)
		{
			f = true;
			break;
		}
		used[k] = i;
	}
	if(f == false)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", i-used[k]);
		for(j = used[k]+1; j<=i; j++)
			printf("%d\n", ans[j]);
	}
	return 0;
}