#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,q,p,a[3];
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<3;i++)
		scanf("%d",&a[i]);
		p=a[0]-a[1];
		q=a[0]-a[2];
		if(fabs(p)<fabs(q))
		printf("A\n");
		else
		printf("B\n");
	}
	return 0;
}
