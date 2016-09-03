//Õ·×ªÏà³ý·¨
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char s[10000],t[10000];
	int i,j,k,ns,nt,max,num,a,b,temp;
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='-')
		  break;
		scanf("%s",t);
		max=0;
		ns=strlen(s),nt=strlen(t);
		for(i=0;i<ns;i++)
		{
			num=0;
		  for(j=0;(i+j)<ns&&j<nt;j++)
		  {
			  if(s[i+j]==t[j])
				num++;
		  }
		  if(num>max)
			max=num;
		}
		for(i=0;i<nt;i++)
		{
			num=0;
			for(j=0;(i+j)<nt&&j<ns;j++)
			{
				if(t[i+j]==s[j])
					num++;
			}
			if(num>max)
			  max=num;
		}
		if(max==0)
			printf("appx(%s,%s) = %d\n",s,t,0);
		else if(2*max==(ns+nt))
			printf("appx(%s,%s) = %d\n",s,t,1);
		else
		{
			a=2*max,b=ns+nt;
			while(1)
			{
				temp=b%a;
				if(temp==0)
				{
				  printf("appx(%s,%s) = %d/%d\n",s,t,2*max/a,(nt+ns)/a);
				  break;
				}
				b=a,a=temp;
			}
		}
	}
	return 0;
}
