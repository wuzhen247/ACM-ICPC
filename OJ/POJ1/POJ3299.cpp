#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	char ch[2];
	double t,d,h,tm1,tm2;
	int a;
	bool f[3];
	while(scanf("%c",&ch[0] )!=EOF)
	{
		if(ch[0]=='E')	break;
		memset(f,false,sizeof(f));
	
		scanf("%lf %c %lf",&tm1 ,&ch[1] ,&tm2);
		getchar();
		switch(ch[0])
		{
			case 'T':t = tm1; f[0] = true;break;
			case 'D':d = tm1; f[1] = true;break;
			case 'H':h = tm1; f[2] = true;break;
		}
		switch(ch[1])
		{
			case 'T':t = tm2; f[0] = true;break;
			case 'D':d = tm2; f[1] = true;break;
			case 'H':h = tm2; f[2] = true;break;
		}
	
		for(int i=0; i< 3;i++)
		{
			if(f[i] == false)
			{
				a = i;
				break;
			}
		}
		switch(a)
		{
			case 2: h=t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10.0);break;
			case 0: t=h-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10.0); break;
			case 1: d=1/(1/273.16-log(((h-t)/0.5555+10)/6.11)/5417.753)-273.16; break;
		}

		printf("T %.1f D %.1f H %.1f\n",t,d,h );
	}
	return 0;
}