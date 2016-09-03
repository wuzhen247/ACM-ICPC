#include<iostream>
#include<cstdio>
using namespace std;
struct point 
{
	int x,y;
}a[705];
inline bool line(point a,point b,point c)
{
	if(((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))==0)
	  return true;
	return false;
}
int main()
{
	int n,i,j,k,temp,max;
	while(scanf("%d",&n)&&n!=0)
	{
		for(k=0;k<n;k++)
		  scanf("%d%d",&a[k].x,&a[k].y);
		max=0;
		for(k=0;k<n-1;k++)
		  for(i=k+1;i<n;i++)
		  {
			  temp=2;
			  for(j=i+1;j<n;j++)
			  {
				  if(line(a[k],a[i],a[j]))
					temp++;
			  }
			  if(temp>max)
				max=temp;
		  }
		printf("%d\n",max);
	}
	return 0;
}
