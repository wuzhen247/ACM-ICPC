//扩展欧几里得算法
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int y[22],a[22],b[22],de[22];
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{	while(scanf("%d",&n)&&n)
	{
		printf("Case #%d:\n",t++);
		my=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&y[i],&a[i],&b[i]);
			de[i]=b[i]-a[i];
			if(a[i]>my)
				my=a[i];
			y[i]%=de[i];
		}
		dis=de[0];
		ans=y[0];
		for(i=1;i<n;i++)
		{
			while(ans%de[i]!=y[i]&&ans<10000)
				ans+=dis;
			if(ans>10000)
				break;
			dis=dis/gcd(dis,de[i])*de[i];
		}
		while(ans<my)
			ans+=dis;
		if(ans>=10000)
			printf("Unknown bugs detected.\n\n");
  		else
   			printf("The actual year is %d.\n\n",ans);
	}
	return 0;
}