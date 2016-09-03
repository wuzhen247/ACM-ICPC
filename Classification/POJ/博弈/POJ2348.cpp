//POJ2348 Euclid's Game 博弈 
/*
一：b是a的整倍数，必胜。
二：b - a < a
     这种情况下只能用b减去a，没有选择，必胜态和必败态互相转换。
三：b - a > a
    这里我们假设b - ax < a;我们来讨论一下减去a * (x - 1)的情况，如果减去以后是必败态，那么当前为必胜态。
如果减去之后为必胜态，我们知道b - ax的状态是b - a(x - 1)唯一可以转移到的状态，因此b - ax为必败态，当前为必胜态。
   所以b - a > a为必胜。
 */ 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;

int main()
{
    int num;
    while (scanf("%d%d", &n, &m),(n||m))
    {
        num = 1;
        while (true)
        {
            if (n < m)
              swap(n,m);
            if (n-m >= m || n % m == 0)
              break;
            num++;
            n -= m;
        }
        if (num % 2)
          printf("Stan wins\n");
        else
          printf("Ollie wins\n");
    }
    return 0;
}

