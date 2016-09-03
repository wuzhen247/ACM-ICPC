/*Hdu4111 Alice and Bob博弈
 * 关键：必胜态到必败态的转换
 * 状态定义：state[i][j] i代表数据为1的堆数，j表示将数据不为1的堆数合并再取完的步数
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int state[55][60000];

int dfs(int i, int j)
{
	if (state[i][j] != -1)	return state[i][j];
	if (j == 1)	return state[i][j] = dfs(i+1, 0);					//某堆数据为1，算到数据为1的堆中
	state[i][j] = 0;
	if (i >= 1 && !dfs(i-1,j))										//拿去一个数据为一的堆
	  state[i][j] = 1;
	if (i >=1 && j && !dfs(i-1,j+1))								//将数据为1的堆与不为1的堆合并
	  state[i][j] = 1;
	if (i >= 2 &&((j && !dfs(i-2, j+3)) || (j==0 && !dfs(i-2,2))))	//将两个数据为1的堆合并
	  state[i][j] = 1;
	if (j >=2 && !dfs(i, j-1))										//将不为1的堆中的数据减少1个
	  state[i][j] = 1;
	return state[i][j];
}

int main()
{
	memset(state, -1, sizeof(state));
	int i, num1, num2, t, c, n, tm;
	scanf("%d", &t);
	for (c = 1; c <= t; c++)
	{
		scanf("%d", &n);
		num1 = num2 = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &tm);
			if (tm == 1)
			  num1++;
			else
			  num2 += tm+1;
		}
		if (num2)	num2--;
//		cout<<num1<<' '<<num2<<endl;
		printf("Case #%d: ", c);
		dfs(num1, num2);	
		if (state[num1][num2])	printf("Alice\n");
		else	printf("Bob\n");
	}
	return 0;
}
