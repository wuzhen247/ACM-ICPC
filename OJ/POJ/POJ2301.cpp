#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,i,s,d,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&s,&d);
		a=(s+d)/2;
		b=(s-d)/2;
		if(a<0||b<0||s<d||(s+d)%2==1)
		  printf("impossible\n");
		else
		  printf("%d %d\n",a,b);
	}
	return 0;
}

