#include<iostream>
#include<cstdio>
#include<cstring>
using  namespace std;
int a[100005],b[100005],c[100005];
int main()
{
    int i,j,n,ans;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        {
          scanf("%d",&a[i]);
        }
        if(n==2)
        {
            printf("%d\n",a[0]+a[1]);
            continue;
        }
        b[0]=a[0];
        for(i=1;i<n;i++)
        {
            if(b[i-1]<0)
              b[i]=a[i];
            else
              b[i]=b[i-1]+a[i];            
        }
        for(i=1;i<n;i++)
        {
          b[i]=max(b[i-1],b[i]);
        }
        
        c[n-1]=a[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(c[i+1]<0)
              c[i]=a[i];
            else
              c[i]=c[i+1]+a[i];
        }
        for(i=n-2;i>=0;i--)
        {
          c[i]=max(c[i],c[i+1]);
        }
        ans=b[1]+c[2];
        for(i=2;i<n;i++)
          ans=max(ans,b[i-1]+c[i]);
        printf("%d\n",ans);
    }
    return 0;
}
