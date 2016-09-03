#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Q
{
	int id;
	int s;
}a[10005];
bool cmp(Q b,Q c)
{
	return b.s<c.s;
}
int main()
{
	int n,i,j,k,sum,t,step,next;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].s);
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		sum=0;
		for(i=1;i<=n;i++)
		{
			if(a[i].id!=-1)
			{
				step=0,j=a[i].id;
				a[i].id=-1;
				while(j!=i)
				{
					next=a[j].id;
					a[j].id=-1;
					step++;
					j=next;
				}
				sum+=step;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


					
