// dfs注意可能有多种结果，输出钱最少的
#include<iostream>
#include<cstdio>
using namespace std;

int c[4]={25,10,5,1},ans[4],m[4],temp[4],C,num;
bool f;

void dfs(int d,int tol)
{
	int n,j,i,tm;
	if(d>3)	return ;
	for(i=0;i<=m[d];i++)
	{
		tm=tol+i*c[d];
		if(tm>C)	break;//	return false;
		if(tm==C)
		{
			f=true;
			for(j=n=0;j<d;j++)	
			  n+=temp[j];
			if(n+i<num)
			{
				for(j=0;j<d;j++)
				  ans[j]=temp[j];
				ans[d]=i;
				for(j=d+1;j<4;j++)
				  ans[j]=0;
				num=n+i;
			}
		//	return true;
			break;
		}
		else
		{
			temp[d]=i;
			dfs(d+1,tm);	//return true;
		}
	}
	//return false;
}


int main()
{
	while(scanf("%d%d%d%d%d",&m[0],&m[1],&m[2],&m[3],&C)&&(m[0]||m[1]||m[2]||m[3]||C))
	{
		num=m[0]+m[1]+m[2]+m[3]+1;
		ans[0]=ans[1]=ans[2]=ans[3]=0;
		f=false;
		dfs(0,0);
		if(f)
		  printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n", ans[0],ans[1],ans[2],ans[3]);
		else
		  printf("Cannot dispense the desired amount.\n");
	}
	return 0;
}
