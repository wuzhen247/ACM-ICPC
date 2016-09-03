#include<iostream>
#include<cstdio>
using namespace std;
int a[502][102];
int main()
{
	int i,j,n,d,num;
	bool flag;
	while(scanf("%d%d",&n,&d)&&(n||d))
	{
		for(i=1;i<=d;i++)
			for(j=1;j<=n;j++)
			  scanf("%d",*(a+i)+j);
		flag=false;
		for(i=1;i<=n;i++)
		{
			num=0;
			for(j=1;j<=d;j++)
			{
				if(a[j][i]==1)
				  num++;
				else
				  break;
			}
			if(num==d)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		  printf("yes\n");
		else
		  printf("no\n");
	}
	return 0;
}



