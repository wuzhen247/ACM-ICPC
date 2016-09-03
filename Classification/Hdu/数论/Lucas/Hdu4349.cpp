/*Hdu4349:����C(n,0),C(n,1)����C(n,n)�������ĸ���
 * Lucas������nչ��Ϊ������,����Ϸ�ʽ����*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, ans;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        ans = 1;
        while (n)
        {
            if (n & 1)
              ans *= 2;
            n >>= 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
