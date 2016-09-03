/*模拟高精度*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 70;
char s[N];
int a[N], b[N], c[N<<1], d[N];

bool mul(int a[], int b[])
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= a[0]; i++)
      for (int j = 1; j <= b[0]; j++)
        c[i+j-1] += a[i]*b[j];
    c[0] = a[0]+b[0];
    for (int i = 1; i <= c[0]; i++)
    {
        if (c[i] > 9)
        {
            c[i+1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    
    sort(c+1, c+1+d[0]);
    for (int i = 1; i <= a[0]; i++)
    {
        if (c[i] != d[i])
          return false;
    }
    for (int i = a[0]+1; i <= c[0]; i++)
      if (c[i] != 0)
        return false;
    return true;
}


int main()
{
    while (scanf("%s", s) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        d[0] = a[0] = strlen(s);
        for (int i = 1; i <= a[0]; i++)
          d[i] = a[i] = int(s[a[0]-i]-'0');
        sort(d+1, d+1+d[0]);
        bool f = true;
        for (int i = 1; i <= a[0]; i++)
        {
            int tm = i;
            b[0] = 0;
            while (tm)
            {
                b[0]++;
                b[b[0]] = tm % 10;
                tm /= 10;
            }
            if (!mul(a, b))
            {
                f = false;
                printf("%s is not cyclic\n", s);
                break;
            }
        }
        if (f)
            printf("%s is cyclic\n", s);
    }
    return 0;
}
