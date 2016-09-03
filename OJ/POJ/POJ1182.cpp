//并查集 食物链
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct DOT
{
	int fa;
	int re;
}a[50005];

int getfather(int x)
{
	if(a[x].fa==x)
	  return x;
	else
	{
		int pa=a[x].fa;
		int temp=getfather(a[x].fa);
		a[x].re=(a[x].re+a[pa].re+3)%3;
		return a[x].fa=temp;
	}
}

void add(int x,int y,int del)
{
	int fx=getfather(x);
	int fy=getfather(y);
	a[fx].fa=fy;
	a[fx].re=(a[y].re-(a[x].re+del)+3)%3;
}

int main()
{
	int n,k,i,j,r,b,c,num,temp1,temp2;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		a[i].fa=i;
		a[i].re=0;
	}
	num=0;
	for(i=0;i<k;i++)
	{
		scanf("%d%d%d",&r,&b,&c);
		if(b>n||c>n||(r==2&&b==c))
		{
			num++;
			continue;
		}
		temp1=getfather(b),temp2=getfather(c);
		if(temp1==temp2)
		{
			if(r==1&&a[b].re!=a[c].re)
			  num++;
			else if(r==2&&(a[c].re-a[b].re+3)%3!=1)
			  num++;
		}
		else
			add(b,c,r-1);
	}
    printf("%d\n",num);
	return 0;
}

