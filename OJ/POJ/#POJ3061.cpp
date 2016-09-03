//计算n个数中连续数之和>=s的最少个数  高效枚举 输入求和 
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int a[N];
int main()
{
	int t,i,j,k,n,s,count,temp;
	cin>>t;
	for(k=0;k<t;k++)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&s);
		for(i=1;i<=n;i++)
		{
			cin>>temp;
			a[i]=temp+a[i-1];
		}
		count=n+1;
		for(i=1,j=1;j<=n;j++)
		{
			if(a[j]-a[i-1]<s)
				continue;
			while(a[j]-a[i]>=s)
				i++;
			if(j-i+1<count)		
				count=j-i+1;
		}
		if(count==n+1)
		cout<<0<<endl;
		else
		cout<<count<<endl;
	}
	return 0;
}

	
