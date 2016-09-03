#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const float pi=acos(-1.0f);
int main()
{
    float a,c,e,s;
    int b,n=0;
    scanf("%f%d%f",&a,&b,&c);
    while(b)
    {
        n++;
        e=pi*a*b/(12*5280);
        s=pi*a*b*3600/(12*5280*c);
        printf("Trip #%d: %.2f %.2f\n",n,e,s);
        scanf("%f%d%f",&a,&b,&c);
    }
    return 0;
}
    
