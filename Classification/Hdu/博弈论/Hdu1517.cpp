//博弈 找规律，推导，9*2*9*2。。。
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

int main()
{
    ll n, p;
    int i;
    while (scanf("%I64d", &n) != EOF)
    {
        p = 1;
        for (i = 1;;i++)
        {
            if (i % 2)
              p *= 9;
            else
              p *= 2;
            if (p >= n)
              break;
        }
        if (i % 2)
          printf("Stan wins.\n");
        else
          printf("Ollie wins.\n");
    }
    return 0;
}
