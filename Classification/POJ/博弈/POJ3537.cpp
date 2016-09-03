//POJ3537 Crosses and Crosses 
//给一个1*n的长方形格子，在格子里轮流画X，最先得到3个连续X的人即为winner
//非递归sg注意初始值和sg[x]的意义，这里指1*x的空白状态
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2010;

int sg[N];
bool vis[N];

void getsg()
{
	memset(sg, 0, sizeof(sg));
	sg[1] = sg[2] = sg[3] = 1;
	for (int i = 4; i < N-4; i++)
	{
		memset(vis, false, sizeof(vis));
		for (int j = 2; j < i; j++)
		{
			if (i-j-1<2)
				vis[sg[j-2]^0] = true;
			else
				vis[sg[j-2]^sg[i-j-1-2]] = true;
		}
		for (int j = 0;;j++)
			if (!vis[j])
			{
				sg[i] = j;
				break;
			}
	}
}

int main()
{
	getsg();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (sg[n])
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}