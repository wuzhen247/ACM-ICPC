//Œª‘ÀÀ„
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,x,y,a,b;
    scanf("%p,%d,%d",&n,&x,&y);
    a=1;
    a<<=x;
    a=~a;
    n=n&a;
    b=6;
    b<<=(y-2);
    n=n|b;
    b=1;
    b<<=(y-2);
    b=~b;
    n=n&b;
    printf("%x\n",n);
    return 0;
}
