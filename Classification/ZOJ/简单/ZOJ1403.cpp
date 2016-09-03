//v - w^2 + x^3 - y^4 + z^5 = target
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int target,v[20],len;
char s[20];

bool cmp(int a,int b)
{
	return a>b;
}

void solve()
{
	int a,b,c,d,e,f;
	for(a=0;a<len;a++)
	  for(b=0;b<len;b++)
		if(b!=a)
		  for(c=0;c<len;c++)
			if(c!=a && c!=a)
			  for(d=0;d<len;d++)
				if(d!=a && d!=b && d!=c)
				  for(e=0;e<len;e++)
					if(e!=a && e!=b && e!=c && e!=d)
					{
						if(v[a]-pow(v[b],2.0)+pow(v[c],3.0)-pow(v[d],4.0)+pow(v[e],5.0)==target)
						{
							printf("%c%c%c%c%c\n",v[a]+'A'-1,v[b]+'A'-1,v[c]+'A'-1,v[d]+'A'-1,v[e]+'A'-1);
							return;
						}
					}
	printf("no solution\n");
}


int main()
{
	int i;
	while(scanf("%d %s",&target,s))
	{
		if(target==0 && strcmp(s,"END")==0)
			break;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			v[i]=int(s[i]-'A'+1);
		}
		sort(v,v+len,cmp);
		solve();
	}
	return 0;
}
