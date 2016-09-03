//求s是否是t的子序列
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char*s,*t,c[200010];
int main()
{
	int a,b,i,j;
	while(gets(c))
	{
		for(j=0;c[j]!=' ';j++);
		t=c+j+1;
		s=c;
		a=j;
		b=strlen(t);
		for(i=0,j=0;i<a;i++,j++)
		{
			for(;j<b;j++)
			{
				if(s[i]==t[j])
				{
					break;
				}
			}
			if(j==b)
				break;
		}
		if(i==a)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
			
				


