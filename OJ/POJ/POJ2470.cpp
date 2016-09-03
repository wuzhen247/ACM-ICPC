#include<cstdio>
using namespace std;
int main()
{
	int n,i,a[100002];
	while(scanf("%d",&n)&&n!=0)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		for(i=1;i<=n;i++)
		{
			if(a[a[i]]!=i)
			{
				printf("not ambiguous\n");
				break;
			}
		}
		if(i>n)
		{
			printf("ambiguous\n");
		}
	}
	return 0;
}

