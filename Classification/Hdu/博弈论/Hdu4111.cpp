/*Hdu4111 Alice and Bob����
 * �ؼ�����ʤ̬���ذ�̬��ת��
 * ״̬���壺state[i][j] i��������Ϊ1�Ķ�����j��ʾ�����ݲ�Ϊ1�Ķ����ϲ���ȡ��Ĳ���
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int state[55][60000];

int dfs(int i, int j)
{
	if (state[i][j] != -1)	return state[i][j];
	if (j == 1)	return state[i][j] = dfs(i+1, 0);					//ĳ������Ϊ1���㵽����Ϊ1�Ķ���
	state[i][j] = 0;
	if (i >= 1 && !dfs(i-1,j))										//��ȥһ������Ϊһ�Ķ�
	  state[i][j] = 1;
	if (i >=1 && j && !dfs(i-1,j+1))								//������Ϊ1�Ķ��벻Ϊ1�ĶѺϲ�
	  state[i][j] = 1;
	if (i >= 2 &&((j && !dfs(i-2, j+3)) || (j==0 && !dfs(i-2,2))))	//����������Ϊ1�ĶѺϲ�
	  state[i][j] = 1;
	if (j >=2 && !dfs(i, j-1))										//����Ϊ1�Ķ��е����ݼ���1��
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
