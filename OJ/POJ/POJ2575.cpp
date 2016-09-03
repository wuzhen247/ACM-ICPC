#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3005];
bool b[3005];
int main()
{
	int n,i;
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=false;
		memset(b,false,sizeof(b));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			b[abs(a[i]-a[i-1])]=true;
		}
		for(i=1;i<n;i++)
		{
			if(b[i]==false)
			{
				printf("Not jolly\n");
				flag=true;
				break;
			}
		}
		if(flag==false)
		  printf("Jolly\n");
	}
	return 0;
}
				

