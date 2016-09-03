#include<iostream>
#include<cstring>
using namespace std;
int a[200030],c[200030];
bool b[200030];
int main()
{
	int front,rear,n,k,temp;
	while(cin>>n>>k)
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(b,false,sizeof(b));
		if(n>=k)
		{
			cout<<n-k<<endl;
			continue;
		}
		front=rear=time=0;
		a[rear]=n,b[n]=true,rear++;
		while(front<rear)
		{
		//	for (int i=front;i<=rear;i++)
		//	cout<<a[i]<<" ";
		//	cout<<endl;
			//int r=rear;
			//for (int i=1)
			if(a[front]==k)
			{
			//	cout<<time<<endl;
				cout<<c[front]<<endl;
				break;
			}
			
			temp=a[front]+1;
			if(temp<=k&&b[temp]==false)
			{
				a[rear]=temp;
				b[temp]=true;
				c[rear]=c[front]+1;
				rear++;
			}
			temp=a[front]-1;
			if(temp>0&&b[temp]==false)
			{
				a[rear]=temp;
				b[temp]=true;
				c[rear]=c[front]+1;
				rear++;
			}
			temp=2*a[front];
			if(a[front]<k&&b[temp]==false)
			{
				a[rear]=temp;
				b[temp]=true;
				c[rear]=c[front]+1;
				rear++;
			}
		//	time++;
			
			front++;
			
		}
	}
	return 0;
}
