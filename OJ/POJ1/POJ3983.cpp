//24µãÓÎÏ·
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a,b,c,d;
bool f;
double F(double a,double b,int p)
{
	switch(p)
	{
		case 1:return a+b;
		case 2:return a-b;
		case 3:return a*b;
		default:return a/b;
	}
}

bool cal(int p1,int p2,int p3,int p4)
{
	double ans=0;
	switch(p4)
	{
		case 1:ans=F(F(F(a,b,p1),c,p2),d,p3);break;
		case 2:ans=F(F(a,b,p1),F(c,d,p3),p2);break;
		case 3:ans=F(a,F(b,F(c,d,p3),p2),p1);break;
		case 4:ans=F(F(a,F(b,c,p2),p1),d,p3);break;
		default :ans=F(a,F(F(b,c,p2),d,p3),p1);break;
	}
	if(ans==24.0)
	  return true;
	return false;
}
char getop(int t)
{
	switch(t)
	{
		case 1:return '+';
		case 2:return '-';
		case 3:return '*';
		default:return '/';
	}
}
void output(int op1,int op2,int op3,int op4)
{
	char p1,p2,p3;
	p1=getop(op1);
	p2=getop(op2);
	p3=getop(op3);
	switch(op4)
	{
		case 1:printf("((%.0lf%c%.0lf)%c%.0lf)%c%.0lf\n",a,p1,b,p2,c,p3,d);break;
		case 2:printf("(%.0lf%c%.0lf)%c(%.0lf%c%.0lf)\n",a,p1,b,p2,c,p3,d);break;
		case 3:printf("%.0lf%c(%.0lf%c(%.0lf%c%.0lf))\n",a,p1,b,p2,c,p3,d);break;
		case 4:printf("(%.0lf%c(%.0lf%c%.0lf))%c%.0lf\n",a,p1,b,p2,c,p3,d);break;
		default:printf("%.0lf%c((%.0lf%c%.0lf)%c%.0lf)\n",a,p1,b,p2,c,p3,d);break;
	}
}
int main()
{
	int i,j,k,p;
	while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
	{
		f=true;
		for(i=1;i<=4&&f;i++)
		  for(j=1;j<=4&&f;j++)
			for(k=1;k<=4&&f;k++)
			  for(p=1;p<=5&&f;p++)
			  {
				  if(cal(i,j,k,p))
				  {	 
					  output(i,j,k,p);
					  f=false;
				  }
			  }
	}
	return 0;
}

