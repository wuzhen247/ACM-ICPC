#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[1010],b[1010];
	int m,n,k,p,i,j,temp1,temp2,s;
	char ch1[10],ch2[10];
	while(cin>>m>>n>>k)
	{
		if(m==0&&n==0&&k==0)
			break;
		cin>>p;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		temp1=temp2=s=0;
		for(i=1;i<=p;i++)
		{
			scanf("%s%d%s%d",ch1,&temp1,ch2,&temp2);
			if(ch1[0]=='c')
			{
				a[temp2]++;
			}
			if(ch1[0]=='p')
			{
				b[temp1]++;
			}
		}
		
		for(j=1;j<=n;j++)
		{
				s+=(m-a[j])*(k-b[j]);
		}
		cout<<s<<endl;
	}
	return 0;
}
