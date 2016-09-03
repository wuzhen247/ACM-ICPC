#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		if(n%2) printf("%d\n",n-1);
		else printf("No Solution!\n");
	}
	return 0;
}
