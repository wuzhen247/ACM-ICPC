//Ê÷×´Êý×é
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 32005
using namespace std;

int n;
int level[N];
int c[N];

int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
void update(int pos)
{
	while(pos <= 32001)
	{
		c[pos]++;
		pos += lowbit(pos);
	}
}

int main()
{
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i <= n ;i++)
	{
		scanf("%d%d", &x, &y);
		level[sum(x+1)]++;
		update(x+1);
	}
	for(int i = 0; i < n; i++)
	  printf("%d\n",level[i]);
	return 0;
}
	

