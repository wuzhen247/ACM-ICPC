/*5*6开关问题，高斯消元*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 35;
int a[N][N];
int t;

void gauss()
{
    for (int i = 0; i < 30; i++)
    {
        int k = i;
        for (; k < 30; k++)
            if (a[k][i])
                break;
        for (int j = 0; j <= 30; j++)
            swap(a[k][j], a[i][j]);
        for (int j = 0; j < 30; j++)
        {
            if (i != j && a[j][i])
                for (int k = 0; k <= 30; k++)
                    a[j][k] ^= a[i][k];
        }
    }
}

int main()
{
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 30; i++)
            scanf("%d", &a[i][30]);
        for (int i = 0; i < 30; i++)
        {
            a[i][i] = 1;
            if (i % 6 != 0)
                a[i-1][i] = 1;
            if (i % 6 != 5)
                a[i+1][i] = 1;
            if (i > 5)
                a[i-6][i] = 1;
            if (i < 24)
                a[i+6][i] = 1;
        }
        gauss();
        printf("PUZZLE #%d\n", cas);
        for (int i = 0; i < 30; i++)
        {
            printf("%d", a[i][30]);
            printf((i+1) % 6 == 0?"\n":" ");
        }

    }
    return 0;
}
