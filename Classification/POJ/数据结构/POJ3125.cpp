//POJ3125 Printer Queue ¶ÓÁÐ²Ù×÷
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int a[10010],front,rear,ans,t,n,p;
bool f;

int main()
{
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		front=rear=ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			rear++;
		}
		while(front<=rear)
		{
			f=false;
			for(j=front;j<rear;j++)
			{
				if(a[j]>a[front])
				{
					f=true;
					break;
				}
			}
	
			if(!f)
			{
				ans++;
				if(p==front)
				  break;
				front++;			
			}
			else
			{
				if(p==front)
				  p=rear;
				a[rear++]=a[front++];
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
