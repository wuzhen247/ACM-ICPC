#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int multi(int a,int n)
{
    int i,ans=1;
    for(i=1;i<=n;i++)
      ans*=a;
    return ans;
}

int main()
{
    int n,a;
    float b,y;
    while(scanf("%f%d",&b,&n)&&(b||n))
    {
        y=1.0f/n;
        a=pow(b,y);
        if((b-multi(a,n))>(multi(a+1,n)-b))
          printf("%d\n",a+1);
        else
          printf("%d\n",a);
    }
    return 0;
}
