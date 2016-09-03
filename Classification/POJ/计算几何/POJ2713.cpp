//告诉你轮胎横截面，要求计算一下，轮胎的最外圈周长。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stdlib.h>
using namespace std;

const double pi=acos(-1.0);
char t[10],c1,c2,s[10],s1[10];
double a,b,c;

int main()
{
	while(scanf("%s",t)!=EOF)
	{
		scanf(" %lf %c %lf %c",&a,&c1,&b,&c2);
		scanf(" %s",s);
		if(s[0]>='0'&&s[0]<='9')
		{
			c=atof(s);
			int x=((a*b*2+c*2540)*pi+500)/1000;
			printf("%s %d %c %d %c %s: %d\n",t,(int)a,c1,(int)b,c2,s,x);
		}
		else
		{
			scanf("%s",s1);
			c=atof(s1);
			int x=((a*b*2+c*2540)*pi+500)/1000;
			printf("%s %d %c %d %c %s %s: %d\n",t,(int)a,c1,(int)b,c2,s,s1,x);
		}
	
	}
	return 0;
}

