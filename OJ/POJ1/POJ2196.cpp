#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int sum1,sum2,sum3,tm,i;
    for(i=2992;i<10000;i++)
    {
        tm=i;
        sum1=sum2=sum3=0;
        while(tm!=0)
        {
            sum1+=tm%10;
            tm/=10;
        }
        sum1+=tm%10;
        tm=i;
        while(tm!=0)
        {
            sum2+=tm%16;
            tm/=16;
        }
        sum2+=tm%16;
        tm=i;
        while(tm!=0)
        {
            sum3+=tm%12;
            tm/=12;
        }
        sum3+=tm%12;
        if(sum1==sum2&&sum2==sum3)
          printf("%d\n",i);
    }
    return 0;
}
