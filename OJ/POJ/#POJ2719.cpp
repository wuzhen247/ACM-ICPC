#include<cstdio>
using namespace std;
int main()
{
	int n,i,j,y,temp,total,x,a[9]={0,1,19,271,3439,40951,468559,5217031,56953279};
	while(scanf("%d",&n)&&n!=0)
	{
		y=0;
		x=n;
		for(i=0;x!=0;i++)
		{
			temp=x%10;
			if(temp>4)
			{
				for(j=0,total=1;j<i;j++)
				{
					total*=10;
				}
				y+=(temp-1)*a[i]+total;
			}
			else
			{
				y+=temp*a[i];
			}
			x/=10;
		}
		printf("%d: %d\n",n,n-y);
	}
	return 0;
}




			

