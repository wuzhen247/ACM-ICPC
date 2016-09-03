//Èı·ÖÁ·Ï°
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-8;

double get(double H, double h, double d)
{
    double low = 0, high = h, mid, mmid, mv, mmv;
    while (high - low >eps)
    {
        mid = (low+high)/2;
        mmid = (low+mid)/2;
        mv = mid+(h-mid)*d/(H-mid);
        mmv = mmid+(h-mmid)*d/(H-mmid);
        if (mv > mmv)
          low = mmid;
        else
          high = mid;
    }   
    return mid+(h-mid)*d/(H-mid);
}
int main()
{
   int t;
   double H, h, d;
   cin>>t;
   while(t--)
   {
       cin>>H>>h>>d;
       printf("%.3lf\n",get(H,h,d));
   }
   return 0;
}
