#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,k,tm;
	while(scanf("%d",&n)!=EOF)
	{
		printf("TERM %d IS ",n);
		k=(sqrt(1+8*n)-1)/2;
		if(k%2)
		{
			if(k*(k+1)==2*n)
			{
				printf("1/%d\n", k);
			}
			else
			{
				tm=n-k*(k+1)/2-1;
				printf("%d/%d\n",1+tm,k+1-tm);
			}
		}
		else
		{
			if(k*(k+1)==2*n)
			{
				printf("%d/1\n",k);
			}
			else
			{
				tm=n-k*(k+1)/2-1;
				printf("%d/%d\n",k+1-tm,1+tm);
			}
		}
	}
	return 0;

}