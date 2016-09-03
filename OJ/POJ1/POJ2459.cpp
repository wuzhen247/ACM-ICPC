#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int account[2100];
int main()
{
	int c,f1,f2,d,i,j,tm,day1,day2;
	scanf("%d%d%d%d",&c,&f1,&f2,&d);
	memset(account,0,sizeof(account));
	for(i=0;i<c;i++)
	{
		scanf("%d%d",&day1,&day2);
		for(j=day1;j<=day2;j++)
		  account[j]++;
	}
	tm=f1-f2;
	for(i=d;i>=1&&tm>0;i--)
	  tm-=account[i];
	printf("%d\n",i+1);
	return 0;
}
