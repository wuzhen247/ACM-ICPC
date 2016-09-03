#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int A,a,B,b,p;
    while(scanf("%d%d%d%d%d",&A,&a,&B,&b,&p)!=EOF)
    {
        if((A<=b&&B<=p)||(B<=a&&A<=p)||(A+B<=p))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

