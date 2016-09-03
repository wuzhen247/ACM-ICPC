#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b,c,d;
    char t;
    while(scanf("%d/%d%c%d/%d",&a,&b,&t,&c,&d)!=EOF)
    {
        if(t=='+')
        {
            a=a*d+b*c;
            b*=d;
            if(a%b==0)
            {
                printf("%d\n",a/b);
                continue;
            }
            c=gcd(a,b);
            printf("%d/%d\n",a/c,b/c);
        }
        else
        {
            a=a*d-b*c;
            if(a==0)
            {
                printf("0\n");
                continue;
            }
            b*=d;
            if(a%b==0)
            {
                printf("%d\n",a/b);
                continue;
            }
            c=gcd(a,b);
            if(a<0)
            {
                printf("%d/%d\n",-a/c,-b/c);
                continue;
            }
            printf("%d/%d\n",a/c,b/c);
        }
    }
    return 0;
}
