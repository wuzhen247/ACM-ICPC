#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m,i,j,k,min,index,temp;
	char a[101][51];
	int b[101]={0},c[101]={0},d[101]={0};
	while(cin>>n>>m)
	{
		getchar();
		for(i=0;i<m;i++)
		{
			gets(a[i]);
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n-1;j++)
			{
				for(k=j+1;k<n;k++)
				{
					if(a[i][k]<a[i][j])
					{
						b[i]++;
					}
				}
			}
		}
		for(i=0;i<m;i++)
		{
			d[i]=b[i];
		}
		for(i=0;i<m-1;i++)
		{
			min=b[i];
			index=i;
			for(j=i+1;j<m;j++)
			{
				if(b[j]<min)
				{
					min=b[j];
					index=j;
				}
			}
			temp=b[i];
			b[i]=b[index];
			b[index]=temp;//ÅÅÐò
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(b[i]==d[j])
				{
					c[i]=j;
				}
			}
		}//¼ìË÷£¬ÕÒ¶ÔÓ¦ÐòºÅ
		for(i=0;i<m;i++)
		{
			cout<<a[c[i]]<<endl;
		}
	}
	return 0;
}



		


		
