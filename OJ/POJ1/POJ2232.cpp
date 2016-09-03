#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

int a[3];

int main()
{
	int n,ans;
	char ch;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%c",&ch);
			getchar();
			switch(ch)
			{
				case 'S': a[0]++;  break;
				case 'F': a[1]++;  break;
				case 'C' : a[2]++;  break;
			}
		}
		if(a[0]==n||a[1]==n||a[2]==n||(a[0]&&a[1]&&a[2]))
			ans=n;
		else 
		{
			if(a[0]==0)	ans=a[1];
			else if(a[1]==0)	ans=a[2];
			else	ans=a[0] ;
		}
		printf("%d\n",ans );
	}
	return 0;
}