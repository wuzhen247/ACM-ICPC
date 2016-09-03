//鸽巢原理
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100005
using namespace std;

int ans[N],used[N];
bool flag;

int main()
{
	int c,n,i,k,j;
	while(scanf("%d%d",&c,&n) && (c||n))
	{
		memset(used,-1,sizeof(used));
		for(i=1; i<=n; i++)
			scanf("%d", &ans[i]);
		used[0] = 0;
		flag = false;
		k = 0;

		for(i=1; i<=n; i++)
		{
			k=(k + ans[i]) %c;
			if(used[k]!=-1)
			{
				flag = true;
				break;
			}
			used[k] = i;
		}
		if(flag == false)
			puts("no sweets");
		else
		{
			printf("%d", used[k]+1 );
			for(j=used[k]+2 ;j<=i; j++)
				printf(" %d", j);
			printf("\n");
		}
	}
	return 0;
}