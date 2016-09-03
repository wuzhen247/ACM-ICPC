//求排序代价和最小 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10010
using namespace std;
struct Niu
{
	int id;
	int value;
}a[N];
bool com(Niu a,Niu b)
{
	return (a.value<b.value);
}
int main()
{
	int n,num,least,ans,inf,i,j,temp,temp1,temp2,next,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].value);
		a[i].id=i;
	}
	sort(a,a+n,com);
	least=a[0].value,sum=0;
	for(i=0;i<n;i++)
	{
		ans=0;
		if(a[i].id!=-1)
		{
			num=1,inf=a[i].value;
			temp=a[i].id,a[i].id=-1;
			while(temp!=i)
			{
				ans+=a[temp].value;
				next=a[temp].id;
				a[temp].id=-1;
				temp=next;
				num++;
			}
			temp1=ans+(num-1)*inf,temp2=ans+(num-1)*least+2*(least+inf);
			if(temp1>temp2)
			  sum+=temp2;
			else
			  sum+=temp1;
		}
	}
	printf("%d\n",sum);
	return 0;
}

				

