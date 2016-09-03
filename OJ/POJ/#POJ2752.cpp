//计算串前缀和后缀相同数，按从小到达顺序输出 
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 400010
using namespace std;
int next[N];
void get_next(char*t)
{
	int i=0,j=-1,n=strlen(t);
	next[0]=-1;
	for(i=0;i<n;i++)
	{
		while(j>=0&&t[i]!=t[j])
			j=next[j];
		if(j<0||t[j]==t[i])
			j++,next[i+1]=j;
	}
}
int main()
{
	char s[N];
	int i,j,n,a[200005];
	while(gets(s)!=NULL)
	{
		memset(next,0,sizeof(next));
		memset(a,0,sizeof(a));
		get_next(s);
		n=strlen(s),j=0;
		while(n!=0)
		{
			a[j++]=n;
			n=next[n];
		}
		for(i=j-1;i>=0;i--)
			cout<<a[i]<<' ';
		cout<<endl;

	}
	return 0;
} 
