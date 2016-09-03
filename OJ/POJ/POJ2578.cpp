#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[3],i;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	for(i=0;i<3;i++)
	{
		if(a[i]<=168)
		{
			printf("CRASH %d\n",a[i]);
			break;
		}
	}
	if(i==3)
	  printf("NO CRASH\n");
	return 0;
}

