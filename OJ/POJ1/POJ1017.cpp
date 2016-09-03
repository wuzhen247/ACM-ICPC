#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,c,d,e,f,tp1,tp2;
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f))
	{
		if(!(a||b||c||d||e||f))
		  break;
		n=0;
		n=f+e+d+(c+3)/4;
		switch(c%4)
		{
			case 0:tp2=0;break;
			case 1:tp2=5;break;
			case 2:tp2=3;break;
			case 3:tp2=1;break;
		}
		tp2+=5*d;
		if(b>tp2)
		  n+=(b-tp2+8)/9;
		tp1=36*n-36*f-25*e-16*d-9*c-4*b;
		if(a>tp1)
		  n+=(a-tp1+35)/36;
		printf("%d\n",n);
	}
	return 0;
}
