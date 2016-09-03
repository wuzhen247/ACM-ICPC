//时间格式转换 
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int t,a,b,c,d,e,f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d/%d/%d-%d:%d:%d",&a,&b,&c,&d,&e,&f);		
    	printf("%02d/%02d/%d-%02d:%02d:%02d%s\n",b,c,a,(d+11)%12+1,e,f,d<12?"am":"pm");
	}
	return 0;
}

