/*计算几何，n个方程求半平面交是否存在*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 100+5;
const double eps = 1e-16;
const double INF = 100000000000.0;
double V[N], U[N], W[N];
int n, cnt;

struct Point
{
    double x, y;
    Point(){}
    Point(double tx, double ty):x(tx), y(ty){}
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    
}p[N], tp[N];

int sgn(double x)
{
    if (fabs(x) < eps)
      return 0;
    if (x < 0)
      return -1;
    return 1;
}

Point intersect(Point p1, Point p2, double a, double b, double c)
{
    double u = fabs(a * p1.x + b * p1.y + c);
    double v = fabs(a * p2.x + b * p2.y + c);
    Point tm;
    tm.x = (p1.x * v + p2.x * u) / (u + v);
    tm.y = (p1.y * v + p2.y * u) / (u + v);
    return tm;
}

void cut(double a, double b, double c)
{
    int curCnt = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (a*p[i].x + b*p[i].y + c <= 0)
          tp[++curCnt] = p[i];
        else
        {
            if (a*p[i-1].x + b*p[i-1].y + c < 0)
                tp[++curCnt] = intersect(p[i], p[i-1], a, b, c);
            if (a*p[i+1].x + b*p[i+1].y + c < 0)
                tp[++curCnt] = intersect(p[i], p[i+1], a, b, c);
        }
    }
    for (int i = 1; i <= curCnt; i++)
        p[i] = tp[i];
    p[curCnt+1] = tp[1], p[0] = tp[curCnt];
    cnt = curCnt;
}

double CalcArea(int n)
{
    double res = 0;
    for(int i = 0;i < n;i++)
        res += (p[i]^p[(i+1)%n]);
    return fabs(res/2);
}

bool judge(int id)
{
    p[1] = Point(0, 0);
    p[2] = Point(INF, 0);
    p[3] = Point(INF, INF);
    p[4] = Point(0, INF);
    p[0] = p[4];
    p[5] = p[1];
    cnt = 4;
    for (int i = 0; i < n; i++)
    {
        if (i != id)
        {
            double a = (V[i] - V[id])/(V[i]*V[id]);
            double b = (U[i] - U[id])/(U[i]*U[id]);
            double c = (W[i] - W[id])/(W[i]*W[id]);
            if (sgn(a) == 0 && sgn(b) == 0)
            {
                if (sgn(c) >= 0)
                  return false;
                continue;
            }
            cut(a, b, c);
        }
    }

    if(sgn(CalcArea(cnt)) == 0)
        return false;
    else return true;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
          scanf("%lf%lf%lf", &V[i], &U[i], &W[i]);
        for (int i = 0; i < n; i++)
        {
            if (judge(i))
              printf("Yes\n");
            else
              printf("No\n");
        }
    }
}
