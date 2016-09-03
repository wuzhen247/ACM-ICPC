#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a,b,i,n,max,step,x,y;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		max=0;
		if(a>b) 
		  y=a,x=b;
		else
		  x=a,y=b;
		for(i=x;i<=y;i++)
		{
			n=i,step=1;
			while(1)
			{
				if(n==1)
				{
				  if(step>max)
					max=step;
					break;
				}
				if(n%2==0)
				  n/=2;
				else
				  n=3*n+1;
				step++;
			}
		}
		printf("%d %d %d\n",a,b,max);
	}
	return 0;
}

