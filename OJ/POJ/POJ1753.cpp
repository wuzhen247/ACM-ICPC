//·­Æå×Ó 
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 65538
using namespace std;
int tr[16]={51200,58368,29184,12544,35968,20032,10016,4880,2248,1252,626,305,140,78,39,19};
struct Sta
{
	int s;
	int step;
}a[100000000];
bool visit[N];
int bfs(int n)
{
	int top,rear,i,temp;
	top=0,rear=1;
	a[top].s=n,a[top].step=0;
	visit[n]=true;
	while(top<rear)
	{
		if(a[top].s==0||a[top].s==65535)
		  return a[top].step;
		for(i=0;i<16;i++)
		{
			temp=a[top].s^tr[i];
			if(visit[temp]==false)
			{
				visit[temp]=true;
				a[rear].s=temp;
				a[rear++].step=a[top].step+1;
				if(temp==0||temp==65535)
				  return a[top].step+1;
			}
		}
		top++;
	}
	return -1;
}
int main()
{
	int i,sum;
	char ch;
	memset(visit,false,sizeof(visit));
	for(i=15,sum=0;i>=0;i--)
	{
		cin>>ch;
		if(ch=='b')
			sum+=1<<i;
	}
	int flag=bfs(sum);
	if(flag==-1)
	  cout<<"Impossible\n";
	else
	  cout<<flag<<endl;
	return 0;
}
