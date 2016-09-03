/*三分法求极值*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 10000+5;
int a[N], b[N], c[N], t, n;

double get(double x)
{
    double ans = a[0]*x*x + b[0]*x + c[0];
    for (int i = 1; i < n; i++)
        ans = max(ans, a[i]*x*x + b[i]*x + c[i]);
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        double l = 0, r = 1000.0, mid, midmid, f1 = 0, f2 = 1000;
        while (r - l > 1e-10)
        {
            mid = (l + r) / 2;
            midmid = (l + mid) / 2;
            f1 = get(midmid);
            f2 = get(mid);
            if (f1 < f2)
                r = mid;
            else
                l = midmid;
        }
        printf("%.4lf\n", f1);
    }
    return 0;
}
