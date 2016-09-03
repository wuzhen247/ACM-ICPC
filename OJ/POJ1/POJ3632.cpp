#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t,n,tm,min,max,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&tm);
        max=min=tm;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&tm);
            if(tm>max)
              max=tm;
            else if(tm<min)
              min=tm;
        }
        printf("%d\n",(max-min)*2);
    }
    return 0;
}
