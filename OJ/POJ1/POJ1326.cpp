#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100],b[100],ch;
	int sum,n;
	bool f;
	while(1)
	{
		sum=0;
		f=false;
		while(1)
		{
			scanf("%s",a);
			if(a[0]=='#')
			{
				f=true;
				break;
			}
			if(a[0]=='0') break;
			scanf("%s %d %c",b,&n,&ch);
			if(ch=='F') sum+=2*n;
			else if(ch=='B') sum+=n+(n+1)/2;
			else 
			{
				if(n<=500) sum+=500;
				else sum+=n;
			}
		}
		if(f==true) break;
		printf("%d\n",sum);
	}
	return 0;
}
