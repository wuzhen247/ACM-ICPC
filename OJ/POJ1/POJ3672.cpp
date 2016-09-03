#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int m,t,u,f,d,i,ans,time;
	char ch;
	ans=time=0;
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	for(i=0;i<t;i++)
	{
		getchar();
		scanf("%c",&ch);
		if(ch=='u'||ch=='d')
		  time+=u+d;
		else
		  time+=2*f;
		if(time<=m)
		  ans++;
	}
	printf("%d\n",ans);
	return 0;
}

