#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
int a[10005];
int main()
{
    int tm,ans,i,j,n;
    a[1]=1;
    for(i=2;i<10001;i++)
    {
        
        a[i]=a[i-1]*i;
        while(a[i]%10==0)
          a[i]/=10;
        if(a[i]>100000)
          a[i]=a[i]%100000;
    }
    while(scanf("%d",&n)!=EOF)
    {
        tm=a[n];
        while(a[n]%10==0)
          a[n]/=10;
        ans=a[n]%10;
        cout<<setiosflags(ios::right);
        cout<<setw(5)<<n;
        printf(" -> %d\n",ans);
    }
    return 0;
}

