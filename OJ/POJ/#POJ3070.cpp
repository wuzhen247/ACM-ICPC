//斐波那契数，矩阵快速幂 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[2][2];
struct A
{
	int b[2][2];
};
A qmi(A r,A base)
{
	int i,j,k;
	A temp;
	memset(temp.b,0,sizeof(temp.b));
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			for(k=0;k<2;k++)
				temp.b[i][j]+=(r.b[i][k]*base.b[k][j])%10000;
			temp.b[i][j]%=10000;
		}
	return temp;
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)&&n!=-1)
	{
		if(n==0)
		{
			printf("%d\n",0);
			continue;
		}
		A r,base;
		r.b[0][0]=1,r.b[0][1]=0,r.b[1][0]=1,r.b[1][1]=1;
		base.b[0][0]=1,base.b[0][1]=1,base.b[1][0]=1,base.b[1][1]=0;
		while(n!=0)
		{
			if(n&1)
				r=qmi(r,base);
			base=qmi(base,base);
			n>>=1;
		}
		cout<<r.b[0][1]%10000<<endl;
	}
	return 0;
}

			


