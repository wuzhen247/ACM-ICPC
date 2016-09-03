#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a[105][105],i,j,ans,max,n,tm;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    max=-1,ans=0;
    for(i=1;i<=n;i++)
    {
        tm=0;
        for(j=1;j<=n;j++)
        {
            if(i==j)
              continue;
            if(a[i][j]>a[j][i])
              tm++;
          //  tm+=a[i][j];
        }
        if(tm>max)
        {
            max=tm;
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
