//Ô¼Éª·ò»·
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a[160],i,j,k,tm,n,t;
    for(i=3;i<151;i++)
    {
        for(j=1;;j++)
        {
            tm=0;
            t=i-1;
            for(k=1;k<i-1;k++)
            {
                tm=(tm+j-1)%t;
                t--;
                if(tm==0)
                  break;
            }
            if(tm!=0)
            {
                a[i]=j;
                break;
            }
        }
    }
    while(scanf("%d",&n)&&n)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}

