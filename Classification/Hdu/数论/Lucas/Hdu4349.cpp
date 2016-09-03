/*Hdu4349:计算C(n,0),C(n,1)……C(n,n)中奇数的个数
 * Lucas定理，将n展开为二进制,用组合方式计算*/
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
