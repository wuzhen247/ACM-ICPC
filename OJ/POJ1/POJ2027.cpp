#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(x<y)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}
	return 0;
}
