//¾ØÐÎÇ¶Ì×
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
int t, n, c[N], ans;

struct rec
{
    int a, b;
}r[N];

bool cmp(rec r1, rec r2)
{
    if (r1.a == r2.a)
      return r1.b < r1.b;
    return r1.a < r2.a;
}

int main()
{
    int i, j, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            r[i].a = min(a, b);
            r[i].b = max(a, b);
            c[i] = 1;
        }
        sort(r, r+n, cmp);
        ans = 1;
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (r[i].b > r[j].b && r[i].a > r[j].a)
                  c[i] = max(c[i], c[j]+1);
            }
            ans = max(ans, c[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
