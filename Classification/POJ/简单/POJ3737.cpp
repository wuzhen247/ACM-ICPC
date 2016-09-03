//¼òµ¥Èı·Ö
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double s, v, r, h, l;
const double PI = acos(-1.0);

int main()
{
    while (scanf("%lf", &s) != EOF)
    {
        double r2 = sqrt(s / PI);
        double r1 = 0.0001;
        double mid, midmid, v1, v2;
        while (r2 - r1 > 0.0001)
        {
            mid = (r1 + r2) /2;
            l = s/(PI*mid) - mid;
            h = sqrt(l*l-mid*mid);
            v2 = mid *mid *h;
            midmid = (r1 + mid) /2;
            l = s/(PI*midmid) - midmid;
            h = sqrt(l*l-midmid*midmid);
            v1 = midmid *midmid *h;
            if (v1 < v2)
                r1 = midmid;
            else
                r2 = mid;
        }
        printf("%.2lf\n%.2lf\n%.2lf\n", v1/3*PI, h, mid);
    }
    return 0;
}
