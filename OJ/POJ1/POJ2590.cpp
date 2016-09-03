// ×ßÂ¥ÌÝ
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int x,y,s,d;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		s=y-x;
		if(s==0)
		{
			printf("0\n");
			continue;
		}
		d=(int)sqrt(s);
		if(s==d*d)
		  printf("%d\n",2*d-1);
		else if(s<=d*d+d)
		  printf("%d\n",2*d);
		else
		  printf("%d\n",2*d+1);
	}
	return 0;
}
