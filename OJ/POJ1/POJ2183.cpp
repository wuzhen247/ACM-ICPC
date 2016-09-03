#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1000000];
int main()
{
    int n,tm,num;
    scanf("%d",&n);
    a[n]=1;
    num=1;
    memset(a,0,sizeof(a));
    while(1)
    {
        tm=(n%100000)/10;
        n=tm*tm;
        n%=1000000;
        if(!a[n])
        {
            a[n]=++num;
        }
        else
        {
            printf("%d %d %d\n",n,num-a[n]+1,num);
            break;
        }
    }
    return 0;
}
