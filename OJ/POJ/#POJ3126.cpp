/*计算四位素数A变化到B的最小步数*/ 
#include<iostream>
#include<cstring> 
using namespace std;
 bool prime(int x)//素数判断 
{
	int i;
	for(i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
			return false;
	}
	return true;
}
bool p[10000],visit[10000];
int a[10000],c[10000];
int main()
{
	int i,j,n,front,rear,temp1,temp2,x,y,step,n1,t1,t2,t3;
	for(i=1000;i<10000;i++)          //打表 
	{
		if(i%2==0)
		{
			p[i]=false;
			continue;
		}
		if(prime(i))
			p[i]=true;
		else
			p[i]=false;
	}
//	for(i=1300;i<=1400;i++)
//		cout<<i<<' '<<p[i]<<endl;
	cin>>n;
	for(n1=0;n1<n;n1++)
	{
		cin>>x>>y;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(visit,false,sizeof(visit));
		front=rear=step=0;
		a[rear]=x,rear++,visit[x]==true;
		temp1=front,temp2=rear;
	//	cout<<front<<' '<<rear<<endl;
		while(front<rear)
		{
			if(a[front]==y)
			{
				cout<<c[front]<<endl;
				break;
			}
			t1=a[front]/10;
			for(j=1;j<=9;j+=2)                     //个位变化 
			{
				t3=t1*10+j;
				if(p[t3]&&visit[t3]==false)
				{
					c[rear]=c[front]+1;
					visit[t3]=true;
					a[rear++]=t3;
				}
			}
			t1=t1/10,t2=a[front]%10;
			for(j=0;j<=9;j++)                       //十位变化 
			{
				t3=t1*100+10*j+t2;
				if(p[t3]&&visit[t3]==false)
				{
					c[rear]=c[front]+1;
					visit[t3]=true;
					a[rear++]=t3;
				}
			}
			t1=t1/10,t2=a[front]%100;
			for(j=0;j<=9;j++)                       //百位变化 
			{
				t3=t1*1000+100*j+t2;
				if(p[t3]&&visit[t3]==false)
				{
					c[rear]=c[front]+1;
					visit[t3]=true;
					a[rear++]=t3;
				}
			}
			t2=a[front]%1000;
			for(j=1;j<=9;j++)                       //千位变化 
			{                 
				t3=j*1000+t2;
				if(p[t3]&&visit[t3]==false)
				{
					c[rear]=c[front]+1;
					visit[t3]=true;
					a[rear++]=t3;
				}
			}
		//	for(j=front;j<rear;j++)
		//		cout<<a[j]<<' ';
		//	cout<<endl;
			front++;
		}
		if(front==rear)
			cout<<"Impossible"<<endl; 
	}
	return 0;
}




			


		
		

