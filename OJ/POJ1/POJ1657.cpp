#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int t,tm1,tm2,s,Max,c,d,e,f;
	char a[3],b[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",a,b);
		s=0;
		tm1=int(a[0]-b[0]);
		tm1=abs(tm1);
		tm2=abs(a[1]-b[1]);
		if(tm1==0&&tm2==0)
		{
			printf("0 0 0 0\n");
			continue;
		}
		c=max(tm1,tm2);
		d=2;
		if(tm1==tm2||tm1==0||tm2==0) d=1;
		e=2;
		if(tm1==0||tm2==0) e=1;
		f=-1;
		if(tm1==tm2) f=1;
		else if((tm1-tm2)%2==0)
			f=2;
		printf("%d %d %d ",c,d,e);
		if(f<0)
			printf("Inf\n");
		else
			printf("%d\n",f);
	}
	return 0;
}

	

